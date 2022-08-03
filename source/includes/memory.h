/**
 * @file memory.h
 * @author pradosh-arduino
 * @brief Header file for memory.c
 * @version v1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);