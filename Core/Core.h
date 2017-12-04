#ifndef Core_h
#define Core_h


#include <stdbool.h>
#include <stdint.h>


void Core_Run();

void Core_Reset();

void Core_Power_Cycle();

bool Core_Set_File(uint8_t* File);

void Core_Set_Input(bool* Buttons);

int16_t* Core_Get_Audio_Samples();

uint32_t* Core_Get_Video_Frame();

char* Core_Get_Version();


#endif
