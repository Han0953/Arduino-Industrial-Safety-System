# 🛡️ Industrial Safety System

> **An Arduino Nano-Based Industrial Safety Monitoring and Early Warning System**

A smart industrial safety prototype designed to improve workplace safety by continuously monitoring **temperature** and **proximity hazards** in real time. Powered by an **Arduino Nano**, the system integrates multiple sensors and warning mechanisms to provide early detection of unsafe conditions while supporting an **Emergency Stop (Manual Override)** feature for immediate system control.

---

## 📖 Overview

The Industrial Safety System is capable of detecting abnormal machine temperatures and unsafe object distances around hazardous work areas. When dangerous conditions are detected, the system immediately activates visual and audible alarms to notify operators, helping reduce the risk of accidents in industrial environments.

---

# ✨ Key Features

- 🌡️ **Real-Time Temperature Monitoring**
  - Continuously measures ambient temperature using the DHT11 sensor.
  - Overheat warning is triggered when the temperature reaches **33°C or above**.

- 📏 **Proximity Hazard Detection**
  - Detects nearby objects or operator hands using the HC-SR04 ultrasonic sensor.
  - Safety alert activates when an object is detected within **10 cm**.

- 🛑 **Emergency Stop (Manual Override)**
  - Instantly pauses all monitoring activities using a single push button.
  - Allows the operator to safely resume system operation when required.

- 📟 **Human Machine Interface (HMI)**
  - Displays real-time temperature, distance, and system status on a **16×2 I2C LCD**.
  - Uses dedicated LED indicators for quick visual feedback.

- 🔊 **Audible Warning System**
  - Passive buzzer generates intermittent and continuous alarm patterns depending on the detected hazard.

---

# 🛠 Hardware Components

| Component | Specification |
|------------|---------------|
| Microcontroller | Arduino Nano (ATmega328P) |
| Temperature Sensor | DHT11 |
| Distance Sensor | HC-SR04 Ultrasonic |
| Display | 16×2 LCD with I2C Module (0x27) |
| Audio Output | Passive Buzzer |
| Visual Indicators | Red LED, Green LED, 220Ω Resistors |
| User Input | Push Button (Emergency Stop) |

---

# 🔌 Pin Configuration

Ensure all hardware connections match the following table before uploading the firmware.

| Component | Arduino Pin |
|------------|-------------|
| DHT11 Data | D2 |
| HC-SR04 Trigger | D3 |
| HC-SR04 Echo | D4 |
| Push Button | D5 |
| Red LED | D6 |
| Green LED | D7 |
| Passive Buzzer | D8 |
| LCD I2C SDA | A4 |
| LCD I2C SCL | A5 |

---

# ⚙️ System Workflow

```text
                Start
                  │
                  ▼
        Initialize Hardware
                  │
                  ▼
 Read Temperature & Distance Sensors
                  │
                  ▼
      Is Emergency Stop Active?
           │              │
          Yes            No
           │              │
           ▼              ▼
     Pause System   Evaluate Sensor Data
                          │
          ┌───────────────┴───────────────┐
          ▼                               ▼
 Temperature ≥ 33°C?             Distance ≤ 10 cm?
          │                               │
         Yes                             Yes
          │                               │
          ▼                               ▼
 Activate Alarm                 Activate Alarm
          │                               │
          └───────────────┬───────────────┘
                          ▼
              Update LCD & LED Status
                          │
                          ▼
                    Repeat Forever
```

---

# 🚀 Installation Guide

## 1. Clone the Repository

```bash
git clone https://github.com/Han0953/Arduino-Industrial-Safety-System.git
```

---

## 2. Open the Project

Launch **Arduino IDE**, then open:

```text
System_Temperature_Ultrasonic.ino
```

---

## 3. Install Required Libraries

Open **Arduino IDE → Library Manager** (`Ctrl + Shift + I`) and install:

| Library | Author |
|----------|--------|
| DHT Sensor Library | Adafruit |
| Adafruit Unified Sensor | Adafruit |
| LiquidCrystal I2C | Frank de Brabander |

---

## 4. Configure Arduino IDE

| Setting | Value |
|----------|-------|
| Board | Arduino Nano |
| Processor | ATmega328P *(Use Old Bootloader if necessary)* |
| Port | Select your Arduino COM Port |

---

## 5. Upload the Firmware

Connect your Arduino Nano via USB, select the correct COM port, and click **Upload**.

---

# 📂 Repository Structure

```text
📦 Arduino-Industrial-Safety-System
│
├── 📄 System_Temperature_Ultrasonic.ino
│   └── Main Arduino Firmware
│
├── 📁 hardware
│   ├── 🖼 circuit_schematic.png
│   ├── 🖼 wiring_diagram.png
│   └── 🖼 prototype_photo.jpg
│
├── 📁 images
│   ├── lcd_display.png
│   ├── temperature_alarm.png
│   └── proximity_alarm.png
│
├── 📄 LICENSE
└── 📄 README.md
```

---

# 📸 Demonstration

| Normal Operation | Temperature Alert | Distance Alert |
|------------------|-------------------|----------------|
| *(Add Image)* | *(Add Image)* | *(Add Image)* |

---

# 🎯 Applications

- Industrial Safety Monitoring
- Machine Overheat Detection
- Operator Safety Protection
- Factory Automation
- Engineering Education
- Embedded Systems Learning

---

# 📜 License

This project was developed for educational, research, and demonstration purposes.

You are welcome to use, modify, and improve this project with proper attribution.

---

<div align="center">

### ⭐ If you find this project useful, consider giving it a Star!

**Designed & Developed by Rehan**

</div>
