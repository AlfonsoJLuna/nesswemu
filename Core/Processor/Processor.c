#include "Processor.h"

#include "Graphics.h"
#include "Memory.h"

#include <stdbool.h>
#include <stdint.h>


static inline void checkPageCrossed(uint16_t address_1, uint16_t address_2)
{
    cpu.page_crossed = (address_1 & 0xFF00) != (address_2 & 0xFF00);
}


#include "Registers.c"
#include "Stack.c"
#include "Addressing.c"
#include "Instructions.c"
#include "Interrupts.c"
#include "Decoder.c"


void Processor_CPU_Reset()
{

}

void Processor_CPU_Power_Cycle()
{

}
