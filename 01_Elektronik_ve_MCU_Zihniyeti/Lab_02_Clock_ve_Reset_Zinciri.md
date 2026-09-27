# Lab 2: Reset, Boot ve Clock Zinciri ⏱️

Bu laboratuvar, cihazın güç verildiği andan ana koda (main) ulaşana kadarki donanım akışını ve saat sinyali dağıtımını belgeler[cite: 1].

## 1. Boot (Uyanış) Akışı
1. **Power-On Reset (POR):** Voltaj (örn. 3.3V) güvenli çalışma seviyesine ulaşana kadar işlemci donanımsal reset durumunda tutulur.
2. **Boot Pin Kontrolü:** Fiziksel `BOOT0` ve `BOOT1` pinlerinin durumuna göre cihazın nereden başlayacağı seçilir:
   * Ana Flash Hafıza (Normal çalışma)
   * System Memory (Üreticinin gömülü bootloader'ı - UART/USB üzerinden kod yüklemek için)
   * SRAM (Hızlı hata ayıklama için)
3. **Reset Handler & SystemInit:** Vector Table üzerinden başlangıç adresi bulunur, çekirdek saat (clock) ayarları başlatılır.
4. **C Startup (crt0):** RAM'deki `.data` ve `.bss` bölümleri başlatılır.
5. **main():** Kullanıcı koduna geçiş yapılır.

## 2. Clock Tree (Saat Ağacı) Blok Diyagramı
```text
[HSI (16 MHz Dahili)] veya [HSE (8 MHz Harici Kristal)] 
         │
         ▼
    [PLL (Faz Kilitlemeli Döngü)] ➔ Frekansı 84 MHz / 168 MHz'e yükseltir
         │
         ▼
    [SYSCLK (Ana Sistem Saati)]
         │
         ├──➔ [AHB Hattı (Yüksek Hızlı)] ➔ CPU, DMA, RAM ve GPIO Portları
         │
         └──➔ [APB Hattı (Düşük Hızlı)] ➔ Timer, UART, I2C, SPI