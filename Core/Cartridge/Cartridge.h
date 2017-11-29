#ifndef Cartridge_h
#define Cartridge_h


#include <stdbool.h>
#include <stdint.h>


bool Cartridge_Load_iNES_File(uint8_t* iNESFile);

uint8_t Cartridge_PRG_Read(uint16_t Address);

void Cartridge_PRG_Write(uint16_t Address, uint8_t Data);

uint8_t Cartridge_CHR_Read(uint16_t Address);

void Cartridge_CHR_Write(uint16_t Address, uint8_t Data);

uint8_t Cartridge_VRAM_Read(uint16_t Address);

void Cartridge_VRAM_Write(uint16_t Address, uint8_t Data);


#endif
