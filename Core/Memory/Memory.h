#ifndef Memory_h
#define Memory_h


#include <stdint.h>


uint8_t Memory_CPU_Read(uint16_t Address);

void Memory_CPU_Write(uint16_t Address, uint8_t Data);


uint8_t Memory_PPU_Read(uint16_t Address);

void Memory_PPU_Write(uint16_t Address, uint8_t Data);


#endif
