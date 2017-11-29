#ifndef Processor_h
#define Processor_h


#include <stdint.h>


uint8_t Processor_RAM_Read(uint16_t Address);

void Processor_RAM_Write(uint16_t Address, uint8_t Data);


#endif
