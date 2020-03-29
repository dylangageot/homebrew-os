/**
 * @file delay.h
 * @brief Prototype for delay using system timer of the BCM2836.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef BCM2836_DELAY_H
#define BCM2836_DELAY_H

/**
 * @brief Wait for an amount of microseconds.
 *
 * @param us Amount of microseconds to wait.
 */
void bcm2836_system_timer_wait(unsigned int us);

#endif /* BCM2836_DELAY_H */
