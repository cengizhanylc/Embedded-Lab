# 🧠 Modül 3: STM32 Bare-Metal Register-Level GPIO Control

Bu proje, **Gömülü Sistemler Mühendislik Yol Haritası** Modül 3 kapsamında; hiçbir hazır kütüphane (HAL/LL) kullanılmadan, doğrudan **ARM Cortex-M CMSIS başlık dosyaları (`stm32f4xx.h`)** ve **Register adresleri** üzerinden yazılmış bare-metal GPIO sürücüsüdür.

---

## 📐 Teknik Özellikler ve Donanım

* **Mikrodenetleyici:** STM32F401RE / STM32F411RE (ARM Cortex-M4)
* **Framework:** CMSIS (Bare-Metal / Register Level)
* **Geliştirme Ortamı:** VS Code + PlatformIO (ARM GNU Toolchain)
* **Çıkış Pini:** `PA5` (Dahili On-Board LED)

---

## 🗄️ Kullanılan Register Adresleri ve İşlevleri

| Register | Offset | Açıklama | Kod Karşılığı |
| :--- | :---: | :--- | :--- |
| **`RCC->AHB1ENR`** | `0x30` | GPIOA Portuna Saat Sinyali (Clock Gate) Verir. | `RCC->AHB1ENR \|= RCC_AHB1ENR_GPIOAEN;` |
| **`GPIOA->MODER`** | `0x00` | PA5 pinini Çıkış (Output - `01`) moduna alır. | `GPIOA->MODER \|= (1U << 10);` |
| **`GPIOA->BSRR`** | `0x18` | Atomik (Atomic Single-Cycle) Set/Reset İşlemi. | `GPIOA->BSRR = GPIO_BSRR_BS5;` |

---

## ⚡ Neden BSRR (Bit Set/Reset Register)?

`ODR` (Output Data Register) kullanmak yerine `BSRR` kullanılmıştır. `BSRR` yazma işlemi **atomik (Atomic Operation)** olduğu için Oku-Değiştir-Yaz (Read-Modify-Write) döngüsüne ihtiyaç duymaz ve kesmelerin (Interrupt) araya girip pin durumunu bozmasını engeller.