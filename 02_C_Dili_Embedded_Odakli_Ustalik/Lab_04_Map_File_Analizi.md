# Lab 4: Map Dosyası ve Hafıza Analizi 🗺️

**Görev:** Derleyici (Compiler) ve Birleştiricinin (Linker) ürettiği `.map` dosyasını inceleyerek yazdığımız C kodunun işlemcinin fiziksel hafızasında nasıl yer tuttuğunu analiz etmek[cite: 1].

## 1. Hafıza Bölümleri (Memory Sections)
Bir `.map` dosyası okunduğunda C dilindeki verilerin şu bölümlere ayrıldığı görülür:

* **`.text` (Flash Bellek):** Çalıştırılabilir makine kodları ve `const` (salt okunur) değişkenler burada tutulur. Elektrik kesilse de silinmez.
* **`.data` (RAM):** Başlangıç değeri atanmış global ve `static` değişkenler burada yaşar (Örn: `int hiz = 100;`). Cihaz boot olurken Flash'tan RAM'e kopyalanırlar.
* **`.bss` (RAM):** Başlangıç değeri atanmamış (veya 0 atanmış) global ve `static` değişkenler burada tutulur. Boot sırasında C startup (crt0) kodu tarafından otomatik olarak sıfırlanırlar.

## 2. Gömülü Sistemde Sık Yapılan Hataların Analizi
1. **Devasa Global Diziler:** `uint8_t buffer[10000];` tanımladığımızda `.bss` bölümü aniden şişer. Kısıtlı RAM'e sahip bir MCU'da (Örn: 20KB RAM) bu durum Linker hatasına (RAM Overflow) yol açar.
2. **`const` Kullanmamak:** Asla değişmeyecek bir sensör kalibrasyon tablosunu (`int tablo[500] = {...}`) başına `const` koymadan tanımlarsak, bu veriler `.data` bölümüne girer. Yani hem Flash'ta yer kaplar hem de başlangıçta RAM'e kopyalanarak değerli RAM alanını kalıcı olarak israf eder. Başlı başına bir mühendislik hatasıdır.
3. **Local Değişkenler:** Fonksiyon içindeki standart yerel değişkenler `.map` dosyasında görünmezler! Çünkü onlar derleme zamanında değil, çalışma zamanında (Runtime) **Stack** üzerinde dinamik olarak yaratılıp yok edilirler[cite: 1].