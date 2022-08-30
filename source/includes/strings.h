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

int strlen(char s[]);
void* strcpy (char *dest, const char *src);
char* strcat(char *dest, const char *src);
int itoa(int num, unsigned char* str, int len, int base);