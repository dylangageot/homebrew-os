#include "rpi/mailbox.h"

rpi_mailbox0_t* mailbox0 = (rpi_mailbox0_t*) RPI_MAILBOX0_BASE;

volatile uint32_t mbox[36] __attribute__((aligned(16)));

extern void invalidate_data_cache(void);
extern void clean_data_cache(void);

uint32_t rpi_mailbox0_read(rpi_mailbox0_channel_t channel) {
    // Loop until we receive something from the requested channel.
    while (1) {
        while ((mailbox0->status0 & RPI_MAILBOX0_EMPTY) != 0);
        // Read the data
        uint32_t data = mailbox0->read;
        uint8_t readChannel = data & 0xFUL;
        // Return it straight away if it's for the requested channel.
        if (readChannel == channel)
            return data & ~0xFUL;
    }
}

void rpi_mailbox0_write(rpi_mailbox0_channel_t channel, uint32_t data) {
    // Wait for space.
    while ((mailbox0->status1 & RPI_MAILBOX0_FULL) != 0);
    // Write the value to the requested channel.
    uint32_t value = (data & ~0xFUL) | channel;
    mailbox0->write = value;
}

uint32_t rpi_mailbox0_property_send(rpi_mailbox0_channel_t channel) {
    // Clean data cache, otherwise we would not be able to read response from VC.
    clean_data_cache();
    // Write to VC.
    rpi_mailbox0_write(channel, (uint32_t) &mbox);
    // Invalidate data cache.
    invalidate_data_cache();
    // Read VC answer.
    rpi_mailbox0_read(channel);
    // Return 1 if command has been proceed, 0 otherwise.
    return mbox[1]==MBOX_RESPONSE_SUCCESS;
}