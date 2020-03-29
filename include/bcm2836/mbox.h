/**
 * @file uart.h
 * @brief Define and prototype for using BCM2836 Mailbox.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-27
 */
#ifndef BCM2836_MAILBOX_H
#define BCM2836_MAILBOX_H

#include "address.h"
#include <stdint.h>

/**
 * Mailbox 0 channels.
 */
typedef enum {
    MBOX_CHANNEL_POWER,
    MBOX_CHANNEL_FRAME,
    MBOX_CHANNEL_VUART,
    MBOX_CHANNEL_VCHIQ,
    MBOX_CHANNEL_LEDS,
    MBOX_CHANNEL_BUTTON,
    MBOX_CHANNEL_TOUCH,
    MBOX_CHANNEL_UNUSED,
    MBOX_CHANNEL_TAGS_ARM_TO_VC,
    MBOX_CHANNEL_TAGS_VC_TO_ARM,
} bcm2836_mbox0_channel_t;

/**
 * Mailbox 0 structure.
 */
typedef struct {
    volatile uint32_t read;
    volatile uint32_t _reserved1[0x10 / 4 - 1];
    volatile uint32_t peek0;
    volatile uint32_t sender0;
    volatile uint32_t status0;
    volatile uint32_t config0;
    volatile uint32_t write;
    volatile uint32_t _reserved2[0x10 / 4 - 1];
    volatile uint32_t peek1;
    volatile uint32_t sender1;
    volatile uint32_t status1;
    volatile uint32_t config1;
} bcm2836_mbox0_t;

/* Mailbox 0 base address */
#define BCM2836_MBOX0_BASE              (BCM2836_PERIPHERAL_BASE + 0xB880UL)

/* This bit is set in the status register if there is no space to write into the mailbox. */
#define BCM2836_MBOX0_FULL              0x80000000UL
/* This bit is set in the status register if there is nothing to read from the mailbox. */
#define BCM2836_MBOX0_EMPTY             0x40000000UL

#define BCM2836_MBOX_REQUEST            0UL
#define BCM2836_MBOX_RESPONSE_SUCCESS   0x80000000UL
#define BCM2836_MBOX_RESPONSE_FAILURE   0x80000001UL
#define BCM2836_MBOX_TAG_SET_CLK_RATE   0x00038002UL
#define BCM2836_MBOX_TAG_LAST           0UL
#define BCM2836_MBOX_TAG_GETSERIAL      0x00010004UL

/**
 * Writes a value to a specific Mailbox 0 channel.
 * @param channel Channel to write in.
 * @param data Value to write.
 */
void bcm2836_mbox0_write(bcm2836_mbox0_channel_t channel, uint32_t data);

/**
 * Reads value from a specific Mailbox 0 channel.
 * @param channel Channel to read from.
 * @return Read value.
 */
uint32_t bcm2836_mbox0_read(bcm2836_mbox0_channel_t channel);

/**
 * Sends a mailbox property call.
 * @param channel Channel to send the mail to.
 * @return 1 if it succeed, 0 otherwise.
 */
uint32_t bcm2836_mbox0_property_send(bcm2836_mbox0_channel_t channel);

#endif //BCM2836_MAILBOX_H
