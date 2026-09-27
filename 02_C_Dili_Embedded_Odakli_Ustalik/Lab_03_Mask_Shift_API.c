/*
 * LAB 3: Bit-field Yerine Mask/Shift API Tasarımı[cite: 1]
 * Görev: C dilindeki Bit-field (struct içi bit alanları) yapıları, derleyiciden 
 * derleyiciye farklılık gösterdiği (Endianness problemi vb.) için donanım 
 * programlamada tehlikelidir. Bunun yerine güvenli maskeleme API'si yazmak.
 */

#include <stdint.h>

// ❌ TEHLİKELİ (Derleyiciye Bağımlı)
struct HataliRegister {
    uint32_t pin_modu  : 2;
    uint32_t hiz_ayari : 2;
    uint32_t bos_alan  : 28;
};

// ✅ GÜVENLİ MÜHENDİSLİK YAKLAŞIMI (Evrensel Maskeleme)
#define REGISTER_ADRES 0x40020000

// Makro API Tasarımı
#define SET_BIT(REG, BIT)     ((REG) |= (1UL << (BIT)))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1UL << (BIT)))
#define READ_BIT(REG, BIT)    (((REG) >> (BIT)) & 1UL)
#define TOGGLE_BIT(REG, BIT)  ((REG) ^= (1UL << (BIT)))

void donanimi_yonet() {
    volatile uint32_t *hedef_reg = (volatile uint32_t *)REGISTER_ADRES;
    
    // 5. Biti donanımsal olarak güvenle 1 yap
    SET_BIT(*hedef_reg, 5);
    
    // 5. Biti donanımsal olarak güvenle 0 yap
    CLEAR_BIT(*hedef_reg, 5);
}