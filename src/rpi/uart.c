#include "rpi/uart.h"

static rpi_uart_t* uart = (rpi_uart_t*) RPI_UART_BASE;

rpi_uart_t* rpi_get_uart(void) {
    return uart;
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