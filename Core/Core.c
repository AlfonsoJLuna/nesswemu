#include "Core.h"

#include "Audio.h"
#include "Cartridge.h"
#include "Controller.h"
#include "Graphics.h"
#include "Processor.h"


void Core_Run()
{
    Processor_CPU_Run();
}

void Core_Reset()
{
    Processor_CPU_Reset();
    Graphics_PPU_Reset();
    Audio_APU_Reset();
}

void Core_Power_Cycle()
{
    Processor_CPU_Power_Cycle();
    Graphics_PPU_Power_Cycle();
    Audio_APU_Power_Cycle();
}

bool Core_Set_File(uint8_t* File)
{
    return Cartridge_File_Load(File);
}

void Core_Set_Input(bool* Buttons)
{
    Controller_Set(Buttons);
}

int16_t* Core_Get_Audio_Samples()
{
    return Audio_Get_Samples();
}

uint32_t* Core_Get_Video_Frame()
{
    return Graphics_Get_Frame();
}
