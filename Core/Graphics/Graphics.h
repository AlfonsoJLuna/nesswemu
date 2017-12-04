#ifndef Graphics_h
#define Graphics_h


#include <stdint.h>


void Graphics_PPU_Reset();

void Graphics_PPU_Power_Cycle();

uint8_t* Graphics_Get_Frame();

uint8_t Graphics_PPU_Register_Read(uint16_t Address);

void Graphics_PPU_Register_Write(uint16_t Address, uint8_t Data);

uint8_t Graphics_PPU_Palette_Read(uint16_t Address);

void Graphics_PPU_Palette_Write(uint16_t Address, uint8_t Data);


#endif
