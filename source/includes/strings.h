/**
 * @file strings.h
 * @author pradosh-arduino
 * @brief Header file for strings.c
 * @version v1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */

#include <stdint.h>
#include <stddef.h>

const char* to_stringU64(uint64_t value);
const char* to_stringI64(int64_t value);
const char* to_hstring64(uint64_t value);
const char* to_hstring32(uint32_t value);
const char* to_hstring16(uint16_t value);
const char* to_hstring8(uint8_t value);
const char* to_stringD(double value, uint8_t decimalPlaces);
const char* to_stringDB(double value);

//int strlen(char s[]);

void* memset(void* bufptr, int value, size_t size);