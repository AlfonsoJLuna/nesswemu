#ifndef Controller_h
#define Controller_h


#include <stdbool.h>
#include <stdint.h>


typedef enum
{
    A,
    B,
    Select,
    Start,
    Up,
    Down,
    Left,
    Right
} button_t;


void Controller_1_Set(button_t Button, bool State);
void Controller_2_Set(button_t Button, bool State);

void Controller_1_Write(uint8_t Data);
void Controller_2_Write(uint8_t Data);

uint8_t Controller_1_Read();
uint8_t Controller_2_Read();


#endif
