/**
 * @file keyboard.h
 * @author pradosh-arduino
 * @brief Header file for PS/2 Keyboard
 * @version v1.0
 * @date 2022-08-05
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */
#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

char currentKey[20];

void Translate(uint8_t scancode, bool upperCase);
