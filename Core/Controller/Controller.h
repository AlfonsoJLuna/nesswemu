#ifndef Controller_h
#define Controller_h


#include <stdbool.h>
#include <stdint.h>


void Controller_Set(bool* Buttons);

void Controller_Write(uint8_t Data);

uint8_t Controller_1_Read();

uint8_t Controller_2_Read();


#endif
