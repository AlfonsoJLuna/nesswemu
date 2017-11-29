#include "Core.h"

#include "Audio.h"
#include "Cartridge.h"
#include "Graphics.h"
#include "Processor.h"


bool Core_Cartridge_File_Load(uint8_t* File)
{
    return Cartridge_File_Load(File);
}


void Core_Controller_1_Set(button_t Button, bool State)
{
    Controller_1_Set(Button, State);
}


void Core_Controller_2_Set(button_t Button, bool State)
{
    Controller_2_Set(Button, State);
}
