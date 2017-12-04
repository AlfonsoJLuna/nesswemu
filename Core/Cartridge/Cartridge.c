#include "Cartridge.h"


typedef struct
{
    uint32_t MagicNumber;
    uint8_t PRGROMSize;
    uint8_t CHRROMSize;
    bool HasPRGRAM;
    uint8_t PRGRAMSize;
    mirroring_t Mirroring;
    uint8_t MapperNumber;
} header_t;


static header_t Header;
static uint8_t PRGROM[16384];
static uint8_t CHRROM[8192];


bool Cartridge_File_Load(uint8_t* File)
{
    Header =
    {
        .MagicNumber = (File[0] << 24) | (File[1] << 16 ) | (File[2] << 8) | File [3];
        .PRGROMSize = File[4];
        .CHRROMSize = File[5];
        .HasPRGRAM = File[6] & 0x04;
        .PRGRAMSIze = File[8];
        .MapperNumber = (File[7] & 0xF0) | ((File[7] & 0xF0) >> 4);
    };

    if (File[6] & 0x08)
    {
        Header.Mirroring = FourScreen;
    }
    else if (File[6] & 0x01)
    {
        Header.Mirroring = Vertical;
    }
    else
    {
        Header.Mirroring = Horizontal;
    }

    if (Header.MagicNumber != 0x1A53454E)
    {
        return 1;
    }

    for (int i = 0; i < 16384; i++)
    {
        PRGROM[i] = File[16 + i];
    }

    for (int i = 0; i < 8192; i++)
    {
        CHRROM[i] = File[16400 + i];
    }

    return 0;
}

mirroring_t Cartridge_Get_Mirroring()
{
    return Header.Mirroring;
}

uint8_t Cartridge_PRG_Read(uint16_t Address)
{
    return PRGROM[Address % 16384];
}

void Cartridge_PRG_Write(uint16_t Address, uint8_t Data)
{

}

uint8_t Cartridge_CHR_Read(uint16_t Address)
{
    return CHRROM[Address % 8192];
}

void Cartridge_CHR_Write(uint16_t Address, uint8_t Data)
{

}
