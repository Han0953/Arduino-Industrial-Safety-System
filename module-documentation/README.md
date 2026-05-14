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
* [cite_start]Memahami prinsip kerja dan integrasi multi-sensor (suhu dan jarak) pada mikrokontroler Arduino[cite: 87].
* [cite_start]Mengontrol multi-aktuator (LCD, LED, Buzzer) sebagai antarmuka peringatan visual dan audio[cite: 88].
* [cite_start]Mengembangkan sistem deteksi bahaya industri (peringatan jarak dan suhu berlebih) secara otomatis[cite: 89].
* [cite_start]Mengimplementasikan logika interupsi manual menggunakan tombol Emergency Stop bersistem toggle[cite: 90].

## ⚙️ Spesifikasi Perangkat Keras
* [cite_start]**Arduino Nano**: ATmega328P, 5V Operating Voltage[cite: 96]. [cite_start]Mikrokontroler pemroses data dan pusat kendali logika sistem[cite: 96].
* [cite_start]**Sensor DHT11**: Range: 0-50°C, Akurasi: ±2°C[cite: 96]. [cite_start]Membaca suhu lingkungan untuk mendeteksi indikasi overheat[cite: 96].
* [cite_start]**Sensor HC-SR04**: Range: 2cm - 400cm, Akurasi: 3mm[cite: 96]. [cite_start]Memancarkan gelombang ultrasonik untuk mendeteksi jarak objek[cite: 96].
* [cite_start]**Modul LCD 16x2 I2C**: 16 Kolom, 2 Baris, Alamat I2C: 0x27[cite: 96]. [cite_start]Antarmuka visual untuk menampilkan data parameter dan status alat[cite: 96].
* [cite_start]**Push Button**: Taktil mekanis, 4 Pin[cite: 96]. [cite_start]Bertindak sebagai saklar digital (Emergency Stop & Resume)[cite: 96].
* [cite_start]**Buzzer Pasif**: Membutuhkan sinyal PWM / tone()[cite: 96]. [cite_start]Aktuator audio untuk memberikan peringatan suara[cite: 96].
* [cite_start]**LED (Merah & Hijau)**: 5mm, Tegangan operasional 2V-3V[cite: 96]. [cite_start]Indikator visual status keamanan sistem (Aman/Peringatan)[cite: 96].
* [cite_start]**Komponen Pendukung**: Rangkaian juga membutuhkan Resistor 220 Ohm, Breadboard, Kabel Jumper (Male-to-Male & Male-to-Female), dan Kabel USB tipe Mini-USB[cite: 96].

## 🚨 Skenario Cara Kerja Alat
* [cite_start]Dalam pengoperasiannya, sistem ini bekerja melalui siklus pembacaan data sensor secara terus-menerus[cite: 81].
* [cite_start]**Mode Aman (Normal):** Pada kondisi ideal di mana suhu di bawah 33°C dan tidak ada objek dalam radius kurang dari 10 cm, LED Hijau akan menyala aktif sebagai penanda status aman, sementara LCD menampilkan data suhu dan jarak[cite: 82].
* [cite_start]**Mode Peringatan (Warning):** Apabila sensor ultrasonik mendeteksi keberadaan objek pada jarak ≤ 10 cm, sistem otomatis beralih ke mode peringatan (jarak dekat) yang ditandai dengan LED Merah berkedip dan buzzer berbunyi terputus-putus[cite: 83].
* [cite_start]**Mode Bahaya (Danger):** Jika sensor DHT11 mendeteksi suhu mencapai ≥ 33°C, mode bahaya (overheat) diaktifkan dengan indikasi LED Merah menyala statis dan buzzer berbunyi panjang secara konstan[cite: 84].
* [cite_start]**Mode Interupsi (Halted):** Terlepas dari kondisi sensor, operator kapan saja dapat menekan tombol Emergency untuk membekukan seluruh operasi sistem (halted), lalu menekannya kembali untuk mereset dan melanjutkan pemantauan (resume)[cite: 85].

## 💡 Kesimpulan
* [cite_start]Prototipe Safety System berbasis Arduino Nano telah sukses diimplementasikan dan diuji[cite: 237].
* [cite_start]Sistem mampu mengintegrasikan tiga bentuk input (suhu, jarak, mekanik) menjadi tiga intervensi keamanan operasional (visual, audio, dan antarmuka teks) yang reliabel, menjadikannya model yang ideal untuk dikembangkan ke skala Industrial Internet of Things (IIoT)[cite: 238].
