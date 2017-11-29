#ifndef Audio_h
#define Audio_h


#include <stdint.h>


uint8_t Audio_APU_Register_Read(uint16_t Address);

void Audio_APU_Register_Write(uint16_t Address, uint8_t Data);


#endif
