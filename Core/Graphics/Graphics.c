#include "Graphics.h"


static uint32_t Frame[256 * 240];


uint64_t Graphics_PPU_Next_VBlank_Cycle()
{
    return 0;
}

void Graphics_PPU_Reset()
{

}

void Graphics_PPU_Power_Cycle()
{

}

uint32_t* Graphics_Get_Frame()
{
    return Frame;
}

uint8_t Graphics_PPU_Register_Read(uint16_t Address)
{
    return 0;
}

void Graphics_PPU_Register_Write(uint16_t Address, uint8_t Data)
{

}

uint8_t Graphics_PPU_Palette_Read(uint16_t Address)
{
    return 0;
}

void Graphics_PPU_Palette_Write(uint16_t Address, uint8_t Data)
{

}
