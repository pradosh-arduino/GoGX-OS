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

char uintTo_StringOutput[128];

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}


const char* to_stringU64(uint64_t value){
    uint8_t size;
    uint64_t sizeTest = value;
    while (sizeTest / 10 > 0){
        sizeTest /= 10;
        size++;
    }

    uint8_t index = 0;
    while(value / 10 > 0){
        uint8_t remainder = value % 10;
        value /= 10;
        uintTo_StringOutput[size - index] = remainder + '0';
        index++;
    }
    uint8_t remainder = value % 10;
    uintTo_StringOutput[size - index] = remainder + '0';
    uintTo_StringOutput[size + 1] = 0; 
    return uintTo_StringOutput;
}

char hexTo_StringOutput[128];
const char* to_hstring64(uint64_t value){
    uint64_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = 8 * 2 - 1;
    for (uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput[size - (i * 2 + 1)] = tmp + (tmp > 9 ? 55 : '0');
        tmp = ((*ptr & 0x0F));
        hexTo_StringOutput[size - (i * 2)] = tmp + (tmp > 9 ? 55 : '0');
    }
    hexTo_StringOutput[size + 1] = 0;
    return hexTo_StringOutput;
}

char hexTo_StringOutput32[128];
const char* to_hstring32(uint32_t value){
    uint32_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = 4 * 2 - 1;
    for (uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput32[size - (i * 2 + 1)] = tmp + (tmp > 9 ? 55 : '0');
        tmp = ((*ptr & 0x0F));
        hexTo_StringOutput32[size - (i * 2)] = tmp + (tmp > 9 ? 55 : '0');
    }
    hexTo_StringOutput32[size + 1] = 0;
    return hexTo_StringOutput32;
}

char hexTo_StringOutput16[128];
const char* to_hstring16(uint16_t value){
    uint16_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = 2 * 2 - 1;
    for (uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput16[size - (i * 2 + 1)] = tmp + (tmp > 9 ? 55 : '0');
        tmp = ((*ptr & 0x0F));
        hexTo_StringOutput16[size - (i * 2)] = tmp + (tmp > 9 ? 55 : '0');
    }
    hexTo_StringOutput16[size + 1] = 0;
    return hexTo_StringOutput16;
}

char hexTo_StringOutput8[128];
const char* to_hstring8(uint8_t value){
    uint8_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t tmp;
    uint8_t size = 1 * 2 - 1;
    for (uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        tmp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput8[size - (i * 2 + 1)] = tmp + (tmp > 9 ? 55 : '0');
        tmp = ((*ptr & 0x0F));
        hexTo_StringOutput8[size - (i * 2)] = tmp + (tmp > 9 ? 55 : '0');
    }
    hexTo_StringOutput8[size + 1] = 0;
    return hexTo_StringOutput8;
}

char intTo_StringOutput[128];
const char* to_stringI64(int64_t value){
    uint8_t isNegative = 0;

    if (value < 0){
        isNegative = 1;
        value *= -1;
        intTo_StringOutput[0] = '-';
    }

    uint8_t size;
    uint64_t sizeTest = value;
    while (sizeTest / 10 > 0){
        sizeTest /= 10;
        size++;
    }

    uint8_t index = 0;
    while(value / 10 > 0){
        uint8_t remainder = value % 10;
        value /= 10;
        intTo_StringOutput[isNegative + size - index] = remainder + '0';
        index++;
    }
    uint8_t remainder = value % 10;
    intTo_StringOutput[isNegative + size - index] = remainder + '0';
    intTo_StringOutput[isNegative + size + 1] = 0; 
    return intTo_StringOutput;
}

char doubleTo_StringOutput[128];
const char* to_stringD(double value, uint8_t decimalPlaces){
    // if (decimalPlaces > 20) decimalPlaces = 20;

    // char* intPtr = (char*)to_string((int64_t)value);
    // char* doublePtr = doubleTo_StringOutput;

    // if (value < 0){
    //     value *= -1;
    // }

    // while(*intPtr != 0){
    //     *doublePtr = *intPtr;
    //     intPtr++;
    //     doublePtr++;
    // }

    // *doublePtr = '.';
    // doublePtr++;

    // double newValue = value - (int)value;

    // for (uint8_t i = 0; i < decimalPlaces; i++){
    //     newValue *= 10;
    //     *doublePtr = (int)newValue + '0';
    //     newValue -= (int)newValue;
    //     doublePtr++;
    // }

    // *doublePtr = 0;
    // return doubleTo_StringOutput;
}

const char* to_stringDB(double value){
    return to_stringD(value, 2);
}