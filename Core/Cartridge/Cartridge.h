#ifndef Cartridge_h
#define Cartridge_h


#include <stdbool.h>
#include <stdint.h>


typedef enum
{
    Horizontal,
    Vertical,
    FourScreen
} mirroring_t;


bool Cartridge_File_Load(uint8_t* File);

mirroring_t Cartridge_Get_Mirroring();

uint8_t Cartridge_PRG_Read(uint16_t Address);

void Cartridge_PRG_Write(uint16_t Address, uint8_t Data);

uint8_t Cartridge_CHR_Read(uint16_t Address);

void Cartridge_CHR_Write(uint16_t Address, uint8_t Data);


#endif
