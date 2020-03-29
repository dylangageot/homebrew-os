#include "bcm2836/mbox.h"

bcm2836_mbox0_t* mbox0 = (bcm2836_mbox0_t*) BCM2836_MBOX0_BASE;

volatile uint32_t mbox_buffer[36] __attribute__((aligned(16)));

extern void invalidate_data_cache(void);
extern void clean_data_cache(void);

uint32_t bcm2836_mbox0_read(bcm2836_mbox0_channel_t channel) {
    // Loop until we receive something from the requested channel.
    while (1) {
        while ((mbox0->status0 & BCM2836_MBOX0_EMPTY) != 0);
        // Read the data
        uint32_t data = mbox0->read;
        uint8_t readChannel = data & 0xFUL;
        // Return it straight away if it's for the requested channel.
        if (readChannel == channel)
            return data & ~0xFUL;
    }
}

void bcm2836_mbox0_write(bcm2836_mbox0_channel_t channel, uint32_t data) {
    // Wait for space.
    while ((mbox0->status1 & BCM2836_MBOX0_FULL) != 0);
    // Write the value to the requested channel.
    uint32_t value = (data & ~0xFUL) | channel;
    mbox0->write = value;
}

uint32_t bcm2836_mbox0_property_send(bcm2836_mbox0_channel_t channel) {
    // Clean data cache, otherwise we would not be able to read response from VC.
    clean_data_cache();
    // Write to VC.
    bcm2836_mbox0_write(channel, (uint32_t) &mbox_buffer);
    // Invalidate data cache.
    invalidate_data_cache();
    // Read VC answer.
    bcm2836_mbox0_read(channel);
    // Return 1 if command has been proceed, 0 otherwise.
    return mbox_buffer[1] == BCM2836_MBOX_RESPONSE_SUCCESS;
}