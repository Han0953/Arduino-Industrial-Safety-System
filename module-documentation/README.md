# 📄 Ringkasan Modul: Prototipe Safety System Mesin Industri Berbasis Arduino Nano

## 🏭 Latar Belakang & Deskripsi Sistem
* Keselamatan kerja di sektor industri menuntut adanya pengawasan yang ketat dan berkelanjutan terhadap kondisi operasional mesin produksi.
* Anomali seperti peningkatan suhu ekstrem (overheat) maupun pelanggaran batas jarak aman oleh pekerja sering kali menjadi pemicu utama kecelakaan kerja dan kerusakan peralatan fisik.
* Oleh karena itu, pengembangan sistem otomatisasi pemantauan menjadi solusi yang krusial untuk menggantikan atau membantu pengawasan manual.
* Sistem ini secara khusus dirancang untuk memitigasi risiko tersebut dengan memberikan respons dan peringatan dini secara real-time berdasarkan fluktuasi kondisi lingkungan di sekitar zona bahaya mesin.
* Secara arsitektur teknis, prototipe sistem keamanan mesin industri ini dikendalikan oleh mikrokontroler Arduino Nano yang bertindak sebagai pusat pemrosesan logika utama (Central Processing Unit).
* Sistem ini mengintegrasikan instrumen input berupa sensor suhu DHT11 untuk memantau termal mesin dan sensor ultrasonik HC-SR04 untuk mendeteksi intrusi objek di area operasional.
* Sebagai antarmuka keluaran (Human Machine Interface), sistem dilengkapi dengan layar LCD 16x2 I2C untuk visualisasi data aktual parameter, indikator LED (Merah dan Hijau) untuk status visual cepat, serta aktuator buzzer pasif sebagai alarm audio.
* Sebagai lapis keamanan tambahan, sistem juga menyertakan tombol mekanis (Push Button) yang difungsikan sebagai saklar Emergency Stop bersistem toggle untuk kontrol interupsi manual dari operator.

## 🎯 Tujuan Project
* Memahami prinsip kerja dan integrasi multi-sensor (suhu dan jarak) pada mikrokontroler Arduino.
* Mengontrol multi-aktuator (LCD, LED, Buzzer) sebagai antarmuka peringatan visual dan audio.
* Mengembangkan sistem deteksi bahaya industri (peringatan jarak dan suhu berlebih) secara otomatis.
* Mengimplementasikan logika interupsi manual menggunakan tombol Emergency Stop bersistem toggle.

## ⚙️ Spesifikasi Perangkat Keras
| Nama Komponen | Spesifikasi Singkat | Fungsi Utama |
| :--- | :--- | :--- |
| **Arduino Nano** | ATmega328P, 5V Operating Voltage | Mikrokontroler pemroses data dan pusat kendali logika sistem. |
| **Sensor DHT11** | Range: 0-50°C, Akurasi: ±2°C | Membaca suhu lingkungan untuk mendeteksi indikasi *overheat*. |
| **Sensor HC-SR04** | Range: 2cm - 400cm, Akurasi: 3mm | Memancarkan gelombang ultrasonik untuk mendeteksi jarak objek. |
| **Modul LCD 16x2**| 16 Kolom, 2 Baris, Alamat I2C: 0x27 | Antarmuka visual untuk menampilkan data parameter dan status alat. |
| **Push Button** | Taktil mekanis, 4 Pin | Bertindak sebagai saklar digital (*Emergency Stop & Resume*). |
| **Buzzer Pasif** | Membutuhkan sinyal PWM / `tone()` | Aktuator audio untuk memberikan peringatan suara. |
| **LED Indikator** | Merah & Hijau (5mm, 2V-3V) | Indikator visual status keamanan sistem (Aman/Peringatan). |
| **Pendukung** | Resistor 220Ω, Kabel Jumper, MB-102 | Komponen pasif dan konektivitas untuk merakit *prototype* di *breadboard*. |

## 🚨 Skenario Cara Kerja Alat
Sistem beroperasi melalui siklus iteratif dengan 4 skenario *state-machine* utama berdasarkan input sensor dan intervensi operator:

| 🛠️ Mode Operasi | 🌡️/📏 Kondisi Pemicu | 🟢/🔴 Respons Visual (LED & LCD) | 🔊 Respons Audio | ⚙️ Status Sistem |
| :--- | :--- | :--- | :--- | :--- |
| 🟢 **Aman (Normal)** | Suhu < 33°C **DAN** Jarak > 10 cm | **LED Hijau ON** <br> LCD: Menampilkan Data Aktual | 🔇 Senyap | Memantau kontinu |
| 🟠 **Peringatan (Warning)**| Jarak Objek <= 10 cm | **LED Merah KEDIP** <br> LCD: "AWAS! Area Dekat" | 🎵 Beep Terputus | Intervensi Jarak |
| 🔴 **Bahaya (Overheat)** | Suhu Lingkungan >= 33°C | **LED Merah ON** <br> LCD: "BAHAYA! Overheat" | 🔊 Alarm Konstan | Kondisi Kritis! |
| ⏸️ **Interupsi (Halted)** | Tombol *E-Stop* Ditekan 1x | **LED Merah ON** <br> LCD: "SYSTEM HALTED!" | 🔇 Senyap | Sistem Dibekukan |

> **Catatan Tambahan:** Pada mode **Interupsi (Halted)**, operator harus menekan tombol *E-Stop* sekali lagi untuk mereset fungsi dan melanjutkan pemantauan (*resume*).

## 💡 Kesimpulan
* Prototipe Safety System berbasis Arduino Nano telah sukses diimplementasikan dan diuji.
* Sistem mampu mengintegrasikan tiga bentuk input (suhu, jarak, mekanik) menjadi tiga intervensi keamanan operasional (visual, audio, dan antarmuka teks) yang reliabel, menjadikannya model yang ideal untuk dikembangkan ke skala Industrial Internet of Things (IIoT).
