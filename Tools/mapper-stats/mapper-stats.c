#include <dirent.h>
#include <stdint.h>
#include <stdio.h>

uint8_t getMapperNumber(char* rom_path)
{
    uint8_t flags_6, flags_7;

    FILE* rom = fopen(rom_path, "rb");
    fseek(rom, 6, SEEK_SET);
    fread(&flags_6, 1, 1, rom);
    fread(&flags_7, 1, 1, rom);
    fclose(rom);

    return (flags_7 & 0xF0) | (flags_6 >> 4);
}

int main()
{
    int number;
    unsigned int mappers[256];

    for (int k = 0; k <= 255; k++)
    {
        mappers[k] = 0;
    }


    DIR* dir;
    struct dirent* ent;

    dir = opendir("C:\\nes\\");

    seekdir(dir, 2);

    while ((ent = readdir(dir)) != NULL)
    {
        number = getMapperNumber(ent->d_name);
        mappers[number] = mappers[number] + 1;
        printf("%u - %s\n", number, ent->d_name);
    }
    closedir (dir);

    for (int i = 0; i <= 255; i++)
    {
        printf("%d %u\n", i, mappers[i]);
    }

    return 0;
}
