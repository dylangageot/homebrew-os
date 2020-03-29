#include <rpi/mailbox.h>
#include "rpi/uart.h"

static rpi_uart_t* uart = (rpi_uart_t*) RPI_UART_BASE;

extern uint32_t mbox[36];

rpi_uart_t* rpi_get_uart(void) {
    return uart;
}

void rpi_uart_init(void) {
    // Wait the end of transmission
    while (uart->FR & RPI_UART_FR_BUSY);

    // Set UART off.
    uart->CR = 0;
    // Flush FEN bit.
    uart->LCRH &= (1UL << 4UL);

    // Set-up UART clock to 4MHz.
    mbox[0] = 9*4;
    mbox[1] = MBOX_REQUEST;
    mbox[2] = MBOX_TAG_SET_CLK_RATE; // set clock rate
    mbox[3] = 12;
    mbox[4] = 12;
    mbox[5] = 2;           // UART clock
    mbox[6] = 4000000;     // 4MHz
    mbox[7] = 0;           // Clear turbo
    mbox[8] = MBOX_TAG_LAST;
    rpi_mailbox0_property_send(MBOX_CHANNEL_TAGS_ARM_TO_VC);

    // Map UART0 to GPIO pins 14 and 15.
    rpi_gpio_t* gpio = rpi_get_gpio();
    gpio->GPFSEL[1] &= ~((RPI_GPIO_GPFSEL_SIZE << 12UL) | (RPI_GPIO_GPFSEL_SIZE << 15UL));
    gpio->GPFSEL[1] |= (RPI_GPIO_GPFSEL_AF0 << 12UL) | (RPI_GPIO_GPFSEL_AF0 << 15UL);
    gpio->GPPUD = 0;

    // Reset pull-up on these pins.
    int i = 150;
    while(i--) { asm volatile("nop"); }
    gpio->GPPUDCLK[0] = (1UL << 14UL) | (1UL << 15UL);
    i=150;
    while(i--) { asm volatile("nop"); }
    gpio->GPPUDCLK[0] = 0;

    // Clear interrupts, set baudrate to 115200, set 8n1 and enable TX, RX and FIFO mode.
    uart->ICR = 0x7FF;
    uart->IBRD = 2;
    uart->FBRD = 0xB;
    uart->LCRH = 0b11UL << 5UL;
    uart->CR = 0x301;
}

void rpi_uart_send_byte(uint8_t data) {
    // If TX FIFO is full, wait for space.
    while (rpi_get_uart()->FR & RPI_UART_FR_TXFF);
    // Send input byte.
    uart->DR = data;
}

void rpi_uart_send_bytes(uint8_t* data, uint32_t size) {
    uint32_t i;
    for (i = 0; i < size; i++) {
        rpi_uart_send_byte(*data);
        ++data;
    }
}

void rpi_uart_send_hex_uint32(uint32_t data) {
    rpi_uart_send_bytes((uint8_t*) "0x", 2);
    int i = 0;
    for (i = 32; i > 0; i -= 4) {
        uint8_t val = (data >> (uint8_t) (i - 4)) & 0xFUL;
        char hex_digit = (val > 9) ? 'A' + val % 10 : '0' + val;
        rpi_uart_send_byte((uint8_t) hex_digit);
    }
}

