#pragma once

typedef struct {
  uint16_t    isr_low;      
  uint16_t    kernel_cs;    
  uint8_t     reserv;     
  uint8_t     attributes;   
  uint16_t    isr_high;     
} __attribute__((packed)) idt_entry;

typedef struct idtp{
    uint16_t limit;
    uint64_t base;
} idtp;

void install_idt();
