/**
 * @file strings.c
 * @author pradosh-arduino
 * @brief Contains String Function from PradoshOS (https://github.com/pradosh-arduino/PradoshOS/blob/main/kernel/src/cstr.cpp)
 * @version v1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright pradosh-arduino (c) 2022
 * 
 */

#include <strings.h>
#include <memory.h>

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

void* strcpy (char *dest, const char *src)
{
  return memcpy (dest, src, strlen (src) + 1);
}

char* strcat(char *dest, const char *src)
{
  strcpy (dest + strlen (dest), src);
  return dest;
}
int itoa(int num, unsigned char* str, int len, int base)
{
	int sum = num;
	int i = 0;
	int digit;
	if (len == 0)
		return -1;
	do
	{
		digit = sum % base;
		if (digit < 0xA)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 0xA;
		sum /= base;
	}while (sum && (i < (len - 1)));
	if (i == (len - 1) && sum)
		return -1;
	str[i] = '\0';
	strrev(str);
	return 0;
}

void strrev(unsigned char *str)
{
	int i;
	int j;
	unsigned char a;
	unsigned len = strlen((const char *)str);
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}