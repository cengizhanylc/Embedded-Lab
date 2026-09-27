# Lab 1: Datasheet ve Pin Mux Analizi 🔍

**Referans Cihaz:** STM32F4 Serisi (Cortex-M4)

**1. Datasheet vs Reference Manual Ayrımı**
* **Datasheet:** Cihazın elektriksel sınırlarını (min/max voltaj, akım limitleri), pinout (bacak dizilimi) haritasını ve fiziksel paket boyutlarını içerir. Bir pini yakıp yakmayacağımızı buradan öğreniriz.
* **Reference Manual:** Donanımın beynidir. Register (yazmaç) haritasını, I2C/SPI/Timer gibi donanım bloklarının nasıl çalıştığını ve hangi bitin hangi işlevi tetiklediğini detaylandırır[cite: 1]. 

**2. Pin Muxing (Çoklama) Örneği: PA9 Pini**
* **Varsayılan Durum:** Analog giriş veya standart dijital I/O (GPIO).
* **Alternatif Fonksiyonlar (AF):** Bu pin yazılımla içeriden yönlendirilerek (Muxing) şu donanımlara bağlanabilir:
  * `USART1_TX` (Seri haberleşme iletim hattı)
  * `TIM1_CH2` (Zamanlayıcı 1, Kanal 2 - PWM çıkışı)
  * `I2C3_SMBA` (I2C uyarı hattı)

**3. Elektriksel Sınırlar**
* STM32F4 serisinde standart bir GPIO pini dışarıya maksimum **±25 mA** akım verebilir (Source) veya çekebilir (Sink).
* Çip üzerindeki tüm pinlerin toplam akım çıkışı genelde **120 mA** ile sınırlıdır. Bu sınır aşıldığında voltaj düşümleri (brownout) veya silikonda fiziksel hasar başlar.