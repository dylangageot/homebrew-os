/**
 * @file uart.h
 * @brief Define and prototype for using BCM2836 UART PL011.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-27
 */
#ifndef RPI_UART_H
#define RPI_UART_H

#include "address.h"
#include "gpio.h"
#include <stdint.h>

/**
 * UART structure.
 */
typedef struct {
    volatile uint32_t DR;
    volatile uint32_t RSRECR;
    volatile uint32_t _reserved1[4];
    volatile uint32_t FR;
    volatile uint32_t ILPR;
    volatile uint32_t IBRD;
    volatile uint32_t FBRD;
    volatile uint32_t LCRH;
    volatile uint32_t CR;
    volatile uint32_t IFLS;
    volatile uint32_t IMSC;
    volatile uint32_t RIS;
    volatile uint32_t MIS;
    volatile uint32_t ICR;
    volatile uint32_t DMACR;
    volatile uint32_t _reserved2[17];
    volatile uint32_t ITCR;
    volatile uint32_t ITIP;
    volatile uint32_t ITOP;
    volatile uint32_t TDR;
} rpi_uart_t;

/* UART base address */
#define RPI_UART_BASE       (RPI_PERIPHERAL_BASE + 0x201000UL)

/* UART DR flags */
#define RPI_UART_DR_OE      (1UL << 11UL)
#define RPI_UART_DR_BE      (1UL << 10UL)
#define RPI_UART_DR_PE      (1UL << 9UL)
#define RPI_UART_DR_FE      (1UL << 8UL)

/* UART RSRECR flags */
#define RPI_UART_RSRECR_OE  (1UL << 3UL)
#define RPI_UART_RSRECR_BE  (1UL << 2UL)
#define RPI_UART_RSRECR_PE  (1UL << 1UL)
#define RPI_UART_RSRECR_FE  (1UL << 0UL)

/* UART FR flags */
#define RPI_UART_FR_TXFE    (1UL << 7UL)
#define RPI_UART_FR_RXFF    (1UL << 6UL)
#define RPI_UART_FR_TXFF    (1UL << 5UL)
#define RPI_UART_FR_RXFE    (1UL << 4UL)
#define RPI_UART_FR_BUSY    (1UL << 3UL)
#define RPI_UART_FR_CTS     (1UL << 0UL)

/**
 * @return UART structure pointer.
 */
rpi_uart_t* rpi_get_uart(void);

/**
 * Sends a single byte through UART.
 * @param data Byte to send.
 */
void rpi_uart_send_byte(uint8_t data);

/**
 * Sends a bytes vector through UART.
 * @param data Bytes to send.
 * @param size Number of bytes.
 */
void rpi_uart_send_bytes(uint8_t* data, uint32_t size);

#endif /* RPI_UART_H */
