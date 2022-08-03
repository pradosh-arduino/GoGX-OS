/**
 * @file graphics.h
 * @author pradosh-arduino
 * @brief Header file for printing text outside kernel.c
 * @version v1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */
#pragma once

#include <stdarg.h>
#include <stddef.h>

extern void (*limine_print)(const char *buf, size_t size);

void print(char msg[]);
void printchr(char msg);