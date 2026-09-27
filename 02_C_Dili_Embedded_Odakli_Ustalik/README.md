# Modül 2: C Dili - Embedded Odaklı Ustalık 💻

Bu modülde, C dilini masaüstü bilgisayarlar için değil, kısıtlı kaynaklara sahip mikrodenetleyiciler (MCU) için kullanmayı öğrendik. Amacımız sadece "çalışan" kod yazmak değil; MISRA-C mantığıyla güvenli, donanım seviyesinde öngörülebilir ve bellek sızıntısına (memory leak) yol açmayan sistemler tasarlamaktır.

## 🧠 Öğrendiğimiz Temel Kavramlar
* **Memory Lifetime (Bellek Ömrü):** Stack vs Heap farkı ve gömülü sistemlerde dinamik bellek tahsisinden (`malloc`/`free`) neden kaçınılması gerektiği[cite: 1].
* **Anahtar Kelimeler:** Donanımla konuşurken derleyiciyi hizaya getiren `volatile`, salt okunur güvenlik sağlayan `const`, değişkenleri dosyalara veya fonksiyonlara hapseden `static` ve dosyalar arası bağ kuran `extern`[cite: 1].
* **Bellek Organizasyonu:** Struct/Union kullanımı, derleyicinin donanım okumasını hızlandırmak için aralara attığı boşluklar (Padding & Alignment)[cite: 1].
* **Dinamik Görev Yönetimi:** Devasa `switch-case` yapıları yerine $O(1)$ karmaşıklıkla çalışan Function Pointer dizileri ile State Machine (Durum Makinesi) tasarımı[cite: 1].

## 🧪 Laboratuvar Görevleri ve Çıktıları
1. **Sahte Peripheral Struct:** Donanım register'larını C dilinde `struct` ve `volatile` kullanarak adreslere map etme (haritalama)[cite: 1].
2. **Ring Buffer (Dairesel Tampon):** Haberleşme (UART/SPI) verilerini veri kaybı olmadan ve `malloc` kullanmadan güvenli bir şekilde depolama[cite: 1].
3. **Mask / Shift API:** Taşınabilirlik (portability) sorunu yaratan Bit-field'lar yerine, evrensel maskeleme fonksiyonları yazma[cite: 1].
4. **Map Dosyası Analizi:** Derleyicinin ürettiği `.map` dosyasını okuyarak kodun RAM ve Flash bellekte nereye, ne kadar yerleştiğini analiz etme[cite: 1].

**Geçme Kriteri:** Pointer, volatile ve bellek yerleşimi (memory layout) hatalarını kod üzerinde veya analizle tespit edebilmek[cite: 1].