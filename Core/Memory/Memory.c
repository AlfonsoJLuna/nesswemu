#include "Memory.h"

#include "Audio.h"
#include "Cartridge.h"
#include "Controller.h"
#include "Graphics.h"


static uint8_t WRAM[0x800];
static uint8_t VRAM[0x800];


static inline uint8_t Mirrored_Read(uint16_t Address)
{
    if (Cartridge_Get_Mirroring() == Horizontal)
    {
        if (Address <= 0x27FF)
        {
            return VRAM[Address % 0x400];
        }
        else
        {
            return VRAM[0x400 + (Address % 0x400)];
        }
    }
    else
    {
        if (Address <= 0x23FF)
        {
            return VRAM[Address % 0x400];
        }
        else if (Address <= 0x27FF)
        {
            return VRAM[0x400 + (Address % 0x400)];
        }
        else if (Address <= 0x2BFF)
        {
            return VRAM[Address % 0x400];
        }
        else
        {
            return VRAM[0x400 + (Address % 0x400)];
        }
    }
}

static inline void Mirrored_Write(uint16_t Address, uint8_t Data)
{
    if (Cartridge_Get_Mirroring() == Horizontal)
    {
        if (Address <= 0x27FF)
        {
            VRAM[Address % 0x400] = Data;
        }
        else
        {
            VRAM[0x400 + (Address % 0x400)] = Data;
        }
    }
    else
    {
        if (Address <= 0x23FF)
        {
            VRAM[Address % 0x400] = Data;
        }
        else if (Address <= 0x27FF)
        {
            VRAM[0x400 + (Address % 0x400)] = Data;
        }
        else if (Address <= 0x2BFF)
        {
            VRAM[Address % 0x400] = Data;
        }
        else
        {
            VRAM[0x400 + (Address % 0x400)] = Data;
        }
    }
}

uint8_t Memory_CPU_Read(uint16_t Address)
{
    if (Address <= 0x1FFF)
    {
        return WRAM[Address % 0x800];
    }
    else if (Address <= 0x3FFF)
    {
        return Graphics_PPU_Register_Read(0x2000 + (Address % 0x8));
    }
    else if (Address <= 0x4013)
    {
        return Audio_APU_Register_Read(Address);
    }
    else if (Addess == 0x4014)
    {
        return Graphics_PPU_Register_Read(Address);
    }
    else if (Address == 0x4015)
    {
        return Audio_APU_Register_Read(Address);
    }
    else if (Address == 0x4016)
    {
        return Controller_1_Read();
    }
    else if (Address == 0x4017)
    {
        return Controller_2_Read();
    }
    else if (Address >= 0x6000)
    {
        return Cartridge_PRG_Read(Address);
    }
    else
    {
        return 0;
    }
}

void Memory_CPU_Write(uint16_t Address, uint8_t Data)
{
    if (Address <= 0x1FFF)
    {
        WRAM[Address % 0x800] = Data;
    }
    else if (Address <= 0x3FFF)
    {
        Graphics_PPU_Register_Write(0x2000 + (Address % 0x8), Data);
    }
    else if (Address <= 0x4013)
    {
        Audio_APU_Register_Write(Address, Data);
    }
    else if (Addess == 0x4014)
    {
        Graphics_PPU_Register_Write(Address, Data);
    }
    else if (Address == 0x4015)
    {
        Audio_APU_Register_Write(Address, Data);
    }
    else if (Address == 0x4016)
    {
        Controller_Write(Data);
    }
    else if (Address == 0x4017)
    {
        Audio_APU_Register_Write(Address, Data);
    }
    else if (Address >= 0x6000)
    {
        Cartridge_PRG_Write(Address, Data);
    }
}

uint8_t Memory_PPU_Read(uint16_t Address)
{
    Address %= 0x4000;

    if (Address <= 0x1FFF)
    {
        return Cartridge_CHR_Read(Address);
    }
    else if (Address <= 0x3EFF)
    {
        return Mirrored_Read(0x2000 + (Address % 0x1000));
    }
    else
    {
        return Graphics_PPU_Palette_Read(0x3F00 + (Address % 0x20));
    }
}

void Memory_PPU_Write(uint16_t Address, uint8_t Data)
{
    Address %= 0x4000;

    if (Address <= 0x1FFF)
    {
        Cartridge_CHR_Write(Address, Data);
    }
    else if (Address <= 0x3EFF)
    {
        Mirrored_Write(0x2000 + (Address % 0x1000), Data);
    }
    else
    {
        Graphics_PPU_Palette_Write(0x3F00 + (Address % 0x20), Data);
    }
}
