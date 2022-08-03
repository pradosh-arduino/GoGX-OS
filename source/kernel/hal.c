/**
 * @file hal.c
 * @author pradosh-arduino
 * @brief Hardware Abstraction Layer (HAL)
 * @version v1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */

#include <hal.h>

void outb(uint16_t port, uint8_t value){
    __asm__ volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

uint8_t inb(uint16_t port){
    uint8_t returnVal;
    __asm__ volatile ("inb %1, %0"
    : "=a"(returnVal)
    : "Nd"(port));
    return returnVal;
}

void outw(uint16_t portNumber, uint16_t data) {
    __asm__ volatile("outw %0, %1" : : "a"(data) , "Nd"(portNumber));
}

void io_wait(){
    __asm__ volatile ("outb %%al, $0x80" : : "a"(0));
}

uint16_t inw(uint16_t portNumber) {
    uint16_t data;
    __asm__ volatile("inw %1, %0" : "=a"(data) : "Nd"(portNumber));
    return data;
}

uint32_t inl(uint16_t portNumber) {
    uint32_t data;
    __asm__ volatile("inl %1, %0" : "=a"(data) : "Nd"(portNumber));
    return data;
}

void outl(uint16_t portNumber, uint32_t data) {
    __asm__ volatile("outl %0, %1" : : "a"(data) , "Nd"(portNumber));
}
