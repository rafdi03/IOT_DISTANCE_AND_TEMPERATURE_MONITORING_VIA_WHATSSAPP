# IOT_DISTANCE_AND_TEMPERATURE_MONITORING_VIA_WHATSSAPP
MONITORING JARAK DAN SUHU IOT VIA WHATSSAPP

Projek iot ini menggunakan Mikrokontroler ESP8266 dan sensornya menggunakan DHT11 dan ULTRASONIC ini sebagai projek sederhana menggunakan mikrokontroler untuk menyambungkan ke WA saya menggunakan [callmebot](https://www.callmebot.com//) sebagai API yang gratis dan dapat digunakan.

Berikut adalah langkah-langkah umum untuk menulis kode :

1. **Persiapan Hardware**:
   - Pastikan Anda memiliki perangkat ESP8266 yang sudah terhubung dengan sensor DHT11 dan sensor ultrasonik (HC-SR04).
   - Hubungkan kabel-kabel dari sensor ke pin yang sesuai pada ESP8266. Pastikan bahwa kabel positif, negatif, dan sinyal terhubung dengan benar.

2. **Instalasi Library**:
   - Pastikan Anda telah menginstal library yang diperlukan. Di dalam kode Anda, Anda menggunakan beberapa library seperti `ESP8266WiFi`, `ESP8266HTTPClient`, `WiFiClient`, dan lainnya. Anda perlu memastikan bahwa library-library ini sudah terinstal di dalam Arduino IDE. Anda bisa menginstalnya melalui menu "Sketch" -> "Include Library" -> "Manage Libraries" dan mencari nama library yang sesuai.

3. **Konfigurasi WiFi**:
   - Gantilah nilai `ssid` dan `password` sesuai dengan informasi jaringan WiFi yang akan Anda gunakan.

4. **Konfigurasi Nomor WhatsApp dan API Key**:
   - Gantilah nilai `phoneNumber` dengan nomor telepon WhatsApp yang akan menerima pesan.
   - Gantilah nilai `apiKey` dengan kunci API yang Anda dapatkan dari layanan "callmebot.com".

5. **Inisialisasi Sensor**:
   - Tentukan pin yang akan digunakan untuk menghubungkan sensor DHT11 dan sensor ultrasonik (HC-SR04) dengan ESP8266. Atur pin tersebut dengan benar dalam definisi pin.

6. **Setup() Function**:
   - Dalam `setup()`, inisialisasikan komunikasi serial dengan `Serial.begin(115200)`.
   - Mulailah koneksi WiFi menggunakan `WiFi.begin(ssid, password)`.
   - Tunggu hingga perangkat terhubung ke jaringan WiFi dengan loop `while(WiFi.status() != WL_CONNECTED)`.
   - Setelah koneksi WiFi berhasil, inisialisasikan sensor DHT11 dan atur mode pin sensor ultrasonik.

7. **Loop() Function**:
   - Dalam `loop()`, gunakan perulangan untuk secara berkala membaca sensor dan mengirimkan pesan WhatsApp.
   - Gunakan variabel `interval` dan `previousMillis` untuk mengontrol frekuensi pengiriman pesan.
   - Dalam setiap iterasi, baca suhu dan kelembaban dari sensor DHT11, lalu baca jarak dari sensor ultrasonik.
   - Buat pesan dengan data yang diukur.
   - Gunakan fungsi `sendMessage()` untuk mengirim pesan ke nomor WhatsApp yang telah ditentukan.

8. **measureDistance() Function**:
   - Ini adalah fungsi yang digunakan untuk mengukur jarak dengan sensor ultrasonik. Ini harus dipanggil dari `loop()`.
   - Fungsi ini mengatur sinyal ultrasonik, mengukur waktu pantulan, dan menghitung jarak.

9. **sendMessage() Function**:
   - Fungsi ini digunakan untuk mengirim pesan WhatsApp dengan data yang diukur.
   - Fungsi ini membangun URL yang berisi nomor telepon, kunci API, dan pesan yang akan dikirim.
   - Menggunakan `HTTPClient`, koneksi HTTP dibuat ke layanan "callmebot.com", dan pesan dikirim.

10. **Uji Kode**: Setelah menulis kode, simpan dan kompilasi kode dalam Arduino IDE. Pastikan tidak ada kesalahan sintaksis atau kompilasi.
    
11. **Upload Kode**: Upload kode ke perangkat ESP8266 Anda.

12. **Monitor Serial**: Gunakan monitor serial dalam Arduino IDE untuk melihat keluaran dari perangkat. Hal ini akan membantu Anda memeriksa apakah perangkat berhasil terhubung ke WiFi dan mengirim pesan WhatsApp dengan benar.

13. **Pantau Hasilnya**: Pastikan perangkat Anda berfungsi seperti yang diharapkan. Pastikan juga bahwa pesan WhatsApp berhasil terkirim ke nomor yang ditentukan.

14. **Perbaikan dan Peningkatan**: Jika diperlukan, Anda dapat memperbaiki atau memodifikasi kode untuk memenuhi kebutuhan khusus Anda atau untuk menambahkan fitur tambahan.

Itu adalah langkah-langkah umum untuk menulis dan menguji kode yang telah Anda berikan. Pastikan untuk memeriksa dokumentasi resmi dari ESP8266, DHT11, HC-SR04, dan layanan "callmebot.com" untuk informasi lebih lanjut tentang penggunaan dan konfigurasi mereka.
