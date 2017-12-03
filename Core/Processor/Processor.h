#ifndef Processor_h
#define Processor_h


#include <stdint.h>


void Processor_CPU_Run();

void Processor_CPU_Reset();

void Processor_CPU_Request_NMI();

void Processor_CPU_Request_IRQ();


uint8_t Processor_RAM_Read(uint16_t Address);

void Processor_RAM_Write(uint16_t Address, uint8_t Data);


#endif
