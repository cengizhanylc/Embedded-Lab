#include "stm32f4xx.h"

/* ================= ====================================================
   BARE-METAL REGISTER SEVİYESİNDE LED YAKMA (GPIOA Pin 5 - Dahili LED)
   ==================================================================== */

// Basit gecikme fonksiyonu (Hardware timer öncesi demo amaçlı)
void delay_ms(volatile uint32_t count) {
    while (count--) {
        for (volatile uint32_t i = 0; i < 3000; i++) {
            __NOP(); // CPU NOP (No Operation) talimatı
        }
    }
}

int main(void) {
    /* 1. CLOCK TREE (Saat Ağacı) AYARI:
       GPIOA çevre biriminin saat hattını aktif et (RCC AHB1ENR Register) */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    /* 2. GPIO MOD SEÇİMİ:
       PA5 pinini Output (Çıkış) moduna getir (MODER Register - 01 = Output) */
    GPIOA->MODER &= ~(3U << (5 * 2)); // 10. ve 11. bitleri temizle (00)
    GPIOA->MODER |=  (1U << (5 * 2)); // 10. biti 1 yap -> (01 = Output)

    /* 3. ANA DÖNGÜ (Main Loop) */
    while (1) {
        // PA5 pinini HIGH yap (LED Yak) -> BSRR Register
        GPIOA->BSRR = GPIO_BSRR_BS5;
        delay_ms(500);

        // PA5 pinini LOW yap (LED Söndür) -> BSRR Register
        GPIOA->BSRR = GPIO_BSRR_BR5;
        delay_ms(500);
    }

    return 0;
}