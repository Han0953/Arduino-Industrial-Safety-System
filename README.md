# 🛡️ Industrial Safety System - Arduino Nano

Prototipe sistem keamanan dan peringatan dini terpadu untuk lingkungan industri. Sistem ini menggunakan **Arduino Nano** sebagai pusat kendali logika untuk memonitor dua parameter krusial: suhu mesin dan jarak aman operasional, dilengkapi dengan fitur *Manual Override* (*Emergency Stop*).

## ✨ Fitur Utama
- **Thermal Monitoring:** Mendeteksi *overheat* mesin secara *real-time* (Ambang batas $\ge$ 33°C).
- **Proximity Alert:** Mendeteksi objek atau tangan operator di zona bahaya (Radius $\le$ 10 cm).
- **Toggle Emergency Stop:** Fitur pembekuan (*halt*) dan pelanjutan (*resume*) sistem secara instan menggunakan satu tombol mekanis.
- **HMI (Human Machine Interface):** Visualisasi data menggunakan LCD 16x2 I2C dan indikator LED.
- **Audio Warning:** Peringatan suara *beep* terputus-putus dan konstan menggunakan *buzzer* pasif.

## 🛠️ Alat dan Bahan
| Komponen | Spesifikasi / Tipe |
| :--- | :--- |
| Mikrokontroler | Arduino Nano (ATmega328P) |
| Sensor Suhu | DHT11 |
| Sensor Jarak | Ultrasonik HC-SR04 |
| Display | LCD 16x2 + Modul I2C (0x27) |
| Audio | Buzzer Pasif |
| Visual | LED 5mm (Merah & Hijau) + Resistor 220Ω |
| Input | Push Button (Tactile) |

## 🔌 Pemetaan Pin (Wiring Diagram)
Pastikan koneksi kabel sesuai dengan tabel di bawah ini sebelum melakukan *upload* program:

- **DHT11 (Data)** $\rightarrow$ Pin D2
- **HC-SR04 (Trig)** $\rightarrow$ Pin D3
- **HC-SR04 (Echo)** $\rightarrow$ Pin D4
- **Push Button** $\rightarrow$ Pin D5 (ke GND)
- **LED Merah** $\rightarrow$ Pin D6
- **LED Hijau** $\rightarrow$ Pin D7
- **Buzzer Pasif** $\rightarrow$ Pin D8
- **LCD I2C (SDA)** $\rightarrow$ Pin A4
- **LCD I2C (SCL)** $\rightarrow$ Pin A5

## 🚀 Cara Instalasi & Penggunaan
1. **Clone Repository:**
   ```bash
   git clone [https://github.com/Han0953/Arduino-Industrial-Safety-System.git](https://github.com/Han0953/Arduino-Industrial-Safety-System.git)
