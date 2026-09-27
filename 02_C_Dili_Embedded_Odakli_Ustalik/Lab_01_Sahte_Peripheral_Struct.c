/*
 * LAB 1: Register Benzeri Sahte Peripheral Struct Oluşturma[cite: 1]
 * Görev: Cihazın datasheet'indeki bellek haritasını (Memory Map) kullanarak, 
 * donanım register'larını C dilindeki struct yapısıyla modellemek.
 */

#include <stdint.h>

// 1. Donanım Yapısının Modellenmesi
// Not: Donanımın arkadan habersizce değiştirebileceği her register 'volatile' olmalıdır!
typedef struct {
    volatile uint32_t MODER;   // Mod ayar register'ı (Offset: 0x00)
    volatile uint32_t OTYPER;  // Çıkış tipi register'ı (Offset: 0x04)
    volatile uint32_t PUPDR;   // Pull-up/Pull-down register'ı (Offset: 0x0C)
    volatile uint32_t IDR;     // Giriş veri okuma register'ı (Offset: 0x10)
    volatile uint32_t ODR;     // Çıkış veri yazma register'ı (Offset: 0x14)
} GPIO_TypeDef;

// 2. Struct Yapısını Gerçek Donanım Adresine Sabitleme (Map etme)
// Datasheet'ten okunan bilgi: GPIOA biriminin başlangıç adresi 0x40020000'dir.
#define GPIOA ((GPIO_TypeDef *) 0x40020000)

void donanimi_baslat() {
    // Artık pointer aritmetiğiyle uğraşmadan, doğrudan donanıma okuma/yazma yapabiliriz.
    // Örnek: PA5 pinini çıkış yapıyoruz.
    GPIOA->MODER |= (1 << 10); 
    
    // Örnek: PA5 pinine enerji veriyoruz (HIGH)
    GPIOA->ODR |= (1 << 5);
}

int main() {
    donanimi_baslat();
    return 0;
}