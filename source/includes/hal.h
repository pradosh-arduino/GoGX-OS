/**
 * @file hal.h
 * @author pradosh-arduino
 * @brief Header file for Hardware Abstraction Layer
 * @version v1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */

#include <stdint.h>

void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
void outw(uint16_t portNumber, uint16_t data);
uint16_t inw(uint16_t portNumber);
uint32_t inl(uint16_t portNumber);
void outl(uint16_t portNumber, uint32_t data);
void io_wait();