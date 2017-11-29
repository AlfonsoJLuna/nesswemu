#ifndef Core_h
#define Core_h


#include "Controller.h"

#include <stdbool.h>
#include <stdint.h>


bool Core_Cartridge_File_Load(uint8_t* File);

void Core_Controller_1_Set(button_t Button, bool State);

void Core_Controller_2_Set(button_t Button, bool State);


#endif
