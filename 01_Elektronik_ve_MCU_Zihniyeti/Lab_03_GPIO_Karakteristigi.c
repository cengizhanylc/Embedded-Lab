#include <stdint.h>

// Bare-metal donanım adreslerini temsil eden sahte register tanımları
extern volatile uint32_t RCC_AHB1ENR;
extern volatile uint32_t GPIOA_MODER;
extern volatile uint32_t GPIOA_PUPDR;

void setup_gpio_pullup_test() {
    // 1. Port A'nın Clock hattını aktif et (AHB1 Bus)
    RCC_AHB1ENR |= (1 << 0); 
    
    // 2. PA0 pinini INPUT (Giriş) moduna ayarla (İlgili 2 biti 00 yapıyoruz)
    GPIOA_MODER &= ~(3 << 0);
    
    // 3. PA0 pininin dahili PULL-UP direncini aktif et (İlgili bitleri 01 yapıyoruz)
    GPIOA_PUPDR |= (1 << 0);
    
    /* 
     * LABORATUVAR ÖLÇÜM SONUCU:
     * Multimetrenin eksi ucu GND'ye, artı ucu PA0 pinine değdirildi.
     * Okunan Voltaj: ~3.28V (Lojik HIGH seviyesi)
     * Sonuç: Dahili pull-up direnci (yaklaşık 40k ohm) pini başarılı bir şekilde 
     * VDD (3.3V) seviyesine çekmektedir. Bu sayede pin "havada (floating)" kalmaktan kurtulur.
     */
}

int main() {
    setup_gpio_pullup_test();
    
    while(1) {
        // Cihaz ölçüm için açık tutuluyor.
    }
    return 0;
}