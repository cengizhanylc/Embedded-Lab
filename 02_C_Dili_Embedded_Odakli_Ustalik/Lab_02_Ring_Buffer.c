/*
 * LAB 2: Ring Buffer (Dairesel Tampon) Yazımı[cite: 1]
 * Görev: Haberleşme protokollerinden (örneğin UART) gelen asenkron verileri 
 * kaçırmamak için statik bellek kullanan bir Ring Buffer tasarlamak.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

// MISRA-C: malloc() kullanmıyoruz. Bellek ihtiyacını derleme zamanında sabitliyoruz.
#define BUFFER_SIZE 16 

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    volatile uint16_t head; // Yazma indeksi
    volatile uint16_t tail; // Okuma indeksi
} RingBuffer_t;

// Sistemin global ama sadece bu dosyada geçerli (static) buffer nesnesi
static RingBuffer_t uart_rx_buffer = { .head = 0, .tail = 0 };

// Veri ekleme fonksiyonu (Genellikle Interrupt - ISR içinden çağrılır)
void RingBuffer_Write(uint8_t data) {
    uint16_t next_head = (uart_rx_buffer.head + 1) % BUFFER_SIZE; // Sona gelince başa dön
    
    if (next_head != uart_rx_buffer.tail) { // Buffer dolu değilse
        uart_rx_buffer.buffer[uart_rx_buffer.head] = data;
        uart_rx_buffer.head = next_head;
    } else {
        // HATA YÖNETİMİ: Buffer Overflow! Yeni veri kaybedildi.
    }
}

// Veri okuma fonksiyonu (Genellikle ana program döngüsünden - main - çağrılır)
bool RingBuffer_Read(uint8_t *data) {
    if (uart_rx_buffer.head == uart_rx_buffer.tail) {
        return false; // Buffer boş
    }
    
    *data = uart_rx_buffer.buffer[uart_rx_buffer.tail];
    uart_rx_buffer.tail = (uart_rx_buffer.tail + 1) % BUFFER_SIZE;
    return true;
}