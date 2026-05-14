#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --- MAPPING PIN ---
#define DHTPIN 2
#define DHTTYPE DHT11
#define TRIG_PIN 3
#define ECHO_PIN 4
#define BTN_EMERGENCY 5
#define LED_MERAH 6
#define LED_HIJAU 7
#define BUZZER 8

// --- INISIALISASI ---
DHT dht(DHTPIN, DHTTYPE);
// Cek address I2C, biasanya 0x27 atau 0x3F.`
LiquidCrystal_I2C lcd(0x27, 16, 2); 

bool isEmergency = false;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BTN_EMERGENCY, INPUT_PULLUP);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Opening
  lcd.setCursor(0,0);
  lcd.print("Safety System");
  lcd.setCursor(0,1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // --- LOGIKA TOMBOL (EMERGENCY & RESET) ---
  if (digitalRead(BTN_EMERGENCY) == LOW) {
    isEmergency = !isEmergency; // Balik statusnya
    delay(500); // Anti-bouncing sederhana
    
    // Kalau balik ke mode normal, bersihin layar LCD 
    if (!isEmergency) {
      lcd.clear(); 
    }
  }

  // --- MODE: EMERGENCY ---
  if (isEmergency) {
    lcd.setCursor(0,0);
    lcd.print("SYSTEM HALTED!  ");
    lcd.setCursor(0,1);
    lcd.print("Press to Resume "); 
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    noTone(BUZZER); // Matiin buzzer
    return; // Stop baca sensor
  }

  // --- BACA SENSOR ---
  float suhu = dht.readTemperature();
  
  // Baca Ultrasonik
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); 
  int jarak = duration * 0.034 / 2;

  // Filter jarak
  if (jarak == 0 || jarak > 50) {
    jarak = 0;
  }

  // --- LOGIKA KONDISI ---
  if (isnan(suhu)) {
    lcd.setCursor(0,0);
    lcd.print("Error DHT11!    ");
    return;
  }

  // MODE: OVERHEAT
  if (suhu >= 33.0) { 
    lcd.setCursor(0,0);
    lcd.print("BAHAYA! Overheat");
    lcd.setCursor(0,1);
    lcd.print("Suhu: " + String(suhu, 1) + "C   ");
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    tone(BUZZER, 2000); // Buzzer pasif bunyi panjang
  } 
  // MODE: WARNING (Ada benda terlalu dekat < 10 cm)
  else if (jarak > 0 && jarak <= 10) { 
    lcd.setCursor(0,0);
    lcd.print("AWAS! Area Dekat");
    lcd.setCursor(0,1);
    lcd.print("Jarak: " + String(jarak) + "cm   ");
    
    // LED Merah & Buzzer kedip/putus-putus
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    tone(BUZZER, 2000); // Bunyi "Tit"
    delay(150);
    digitalWrite(LED_MERAH, LOW);
    noTone(BUZZER); // Matiin suara "Tit"
    delay(150);
  } 
  // MODE: NORMAL
  else { 
    lcd.setCursor(0,0);
    lcd.print("System Normal   ");
    lcd.setCursor(0,1);
    lcd.print("S:" + String(suhu, 1) + "C J:" + String(jarak) + "cm  ");
    
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_HIJAU, HIGH);
    noTone(BUZZER); // Matiin buzzer
  }
  
  delay(100); 
}