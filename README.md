<div align="center">

# 🛡️ Industrial Safety System

### Arduino Nano-Based Industrial Safety Monitoring & Early Warning System

<img src="./assets/banner.png" width="100%">

![Arduino](https://img.shields.io/badge/Board-Arduino_Nano-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-success?style=for-the-badge)

*A smart embedded safety prototype for industrial environments capable of monitoring temperature, detecting hazardous proximity, and providing real-time visual and audible warnings.*

</div>

---

# 📖 Overview

The **Industrial Safety System** is an Arduino Nano-based embedded monitoring prototype developed to improve workplace safety through continuous environmental monitoring.

The system simultaneously measures **machine temperature** and **operator proximity** to detect unsafe operating conditions before they become critical.

Whenever abnormal conditions are detected, the system immediately activates multiple warning mechanisms, including LED indicators, a passive buzzer, and a 16×2 LCD display.

An integrated **Emergency Stop (Manual Override)** button allows operators to instantly pause or resume the monitoring process whenever necessary.

---

# ✨ Features

- 🌡️ Real-Time Temperature Monitoring
- 📏 Ultrasonic Proximity Detection
- 🛑 Emergency Stop / Resume
- 📟 LCD Human-Machine Interface
- 🔴🟢 Visual LED Status Indicators
- 🔊 Passive Buzzer Alarm
- ⚡ Continuous Real-Time Monitoring
- 🎓 Educational Embedded System Prototype

---

# 🎯 Objectives

- Integrate multiple sensors into a single embedded monitoring system.
- Detect machine overheating in real time.
- Detect unsafe object proximity around hazardous areas.
- Provide visual and audible warning mechanisms.
- Implement manual Emergency Stop functionality.
- Demonstrate embedded programming using Arduino Nano.

---

# 🛠 Hardware Components

| Component | Specification | Function |
|------------|---------------|----------|
| Arduino Nano | ATmega328P | Main Controller |
| DHT11 | Temperature Sensor | Thermal Monitoring |
| HC-SR04 | Ultrasonic Sensor | Distance Detection |
| LCD 16×2 | I2C (0x27) | Human Machine Interface |
| Passive Buzzer | PWM Compatible | Audible Warning |
| Red LED | 5mm | Danger Indicator |
| Green LED | 5mm | Safe Indicator |
| Push Button | Tactile Switch | Emergency Stop |

---

# 🔌 Pin Configuration

| Component | Pin |
|------------|-----|
| DHT11 | D2 |
| HC-SR04 Trigger | D3 |
| HC-SR04 Echo | D4 |
| Push Button | D5 |
| Red LED | D6 |
| Green LED | D7 |
| Passive Buzzer | D8 |
| LCD SDA | A4 |
| LCD SCL | A5 |

---

# ⚙️ Operating Modes

| Mode | Trigger | LED | LCD | Buzzer |
|------|---------|-----|-----|---------|
| 🟢 Safe | Temp < 33°C & Distance > 10 cm | Green | Live Sensor Data | Silent |
| 🟠 Warning | Distance ≤ 10 cm | Blinking Red | WARNING | Beep |
| 🔴 Danger | Temp ≥ 33°C | Solid Red | OVERHEAT | Continuous Alarm |
| ⏸ Halted | Emergency Stop | Red | SYSTEM HALTED | Silent |

---

# 🔄 System Workflow

```text
                 Power ON
                     │
                     ▼
          Initialize Hardware
                     │
                     ▼
      Read Temperature & Distance
                     │
                     ▼
      Emergency Stop Activated?
              │           │
             Yes         No
              │           │
              ▼           ▼
       Pause Monitoring   Analyze Sensor Data
                              │
            ┌─────────────────┴─────────────────┐
            ▼                                   ▼
   Temperature ≥ 33°C?                 Distance ≤ 10 cm?
            │                                   │
           Yes                                 Yes
            │                                   │
            ▼                                   ▼
      Trigger Alarm                    Trigger Warning
            │                                   │
            └─────────────────┬─────────────────┘
                              ▼
               Update LCD, LEDs & Buzzer
                              │
                              ▼
                     Repeat Continuously
```

---

# 📊 System Architecture

```text
               DHT11
                  │
                  │
             HC-SR04
                  │
                  ▼
          Arduino Nano
        ┌──────┼──────┐
        ▼      ▼      ▼
      LCD     LEDs  Buzzer
                 │
                 ▼
          Emergency Button
```

---

# 🚀 Installation

## Clone Repository

```bash
git clone https://github.com/Han0953/Arduino-Industrial-Safety-System.git
```

## Open Project

```text
System_Temperature_Ultrasonic.ino
```

## Required Libraries

| Library |
|----------|
| DHT Sensor Library |
| Adafruit Unified Sensor |
| LiquidCrystal_I2C |

## Arduino IDE Configuration

| Setting | Value |
|----------|-------|
| Board | Arduino Nano |
| Processor | ATmega328P (Old Bootloader if needed) |
| Port | Your Arduino COM Port |

Click **Upload** after compilation.

---

# 📂 Repository Structure

```text
📦 Arduino-Industrial-Safety-System
│
├── 📄 README.md
├── 📄 LICENSE
├── 📄 System_Temperature_Ultrasonic.ino
│
├── 📁 assets
│   ├── banner.png
│   ├── prototype.jpg
│   ├── wiring_diagram.png
│   ├── circuit_schematic.png
│   ├── block_diagram.png
│   └── demo.gif
│
└── 📁 images
    ├── lcd_display.jpg
    ├── temperature_alarm.jpg
    └── warning_mode.jpg
```

---

# 📸 Preview

| Prototype | Wiring Diagram |
|------------|----------------|
| *(Add Image)* | *(Add Image)* |

| Safe Mode | Warning Mode | Danger Mode |
|------------|--------------|-------------|
| *(Image)* | *(Image)* | *(Image)* |

---

# 🌍 Applications

- Industrial Safety Monitoring
- Smart Factory
- Machine Protection
- Engineering Laboratory
- Embedded Systems Education
- Industrial Automation

---

# 🚀 Future Improvements

- 📡 ESP32 Wi-Fi Version
- ☁ MQTT Cloud Dashboard
- 📱 Mobile Notifications
- 📊 Data Logging
- 🌡 Temperature History
- 🤖 AI-Based Predictive Maintenance
- 📈 Web Dashboard

---

# 📜 License

Released under the **MIT License**.

Feel free to use, modify, and improve this project with proper attribution.

---

<div align="center">

### ⭐ If this project helped you, consider giving it a Star!

**Designed & Developed by Rehan**

*Electronics • Embedded Systems • Arduino • IoT • Industrial Automation*

</div>
