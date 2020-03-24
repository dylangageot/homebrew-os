/**
 * @file delay.h
 * @brief Prototype for delay using system timer.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */

#ifndef RPI_DELAY_H
#define RPI_DELAY_H

/**
 * @brief Wait for an amount of microseconds.
 *
 * @param us Amount of microseconds to wait.
 */
void udelay(unsigned int us);

#endif /* RPI_DELAY_H */
