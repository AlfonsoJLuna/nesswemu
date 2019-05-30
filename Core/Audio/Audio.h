#ifndef Audio_h
#define Audio_h


#include <stdint.h>


void Audio_APU_Reset();

void Audio_APU_Power_Cycle();

int16_t* Audio_Get_Samples();

uint8_t Audio_APU_Register_Read(uint16_t Address);

void Audio_APU_Register_Write(uint16_t Address, uint8_t Data);


#endif
