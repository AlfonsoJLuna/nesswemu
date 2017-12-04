#include "Controller.h"


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


typedef struct
{
    bool Buttons[8];
    bool Strobe;
    uint8_t Index;
} controller_t;


static controller_t Controller1 = {0};
static controller_t Controller2 = {0};


void Controller_Set(bool* Buttons)
{
    for (int i = 0; i <= 7; i++)
    {
        Controller1.Buttons[i] = Buttons[i];
        Controller2.Buttons[i] = Buttons[8 + i];
    }
}

void Controller_Write(uint8_t Data)
{
    Controller1.Strobe = Data & 0x01;
    Controller2.Strobe = Data & 0x01;

    if (Controller1.Strobe)
    {
        Controller1.Index = 0;
    }

    if (Controller2.Strobe)
    {
        Controller2.Index = 0;
    }
}

uint8_t Controller_1_Read()
{
    if (Controller1.Strobe)
    {
        Controller1.Index = 0;
    }

    bool State;

    if (Controller1.Index <= 7)
    {
        State = Controller1.Buttons[Controller1.Index];
    }
    else
    {
        Controller1.Index = 8;
        State = 1;
    }

    Controller1.Index++;

    return 0x40 | State;
}

uint8_t Controller_2_Read()
{
    if (Controller2.Strobe)
    {
        Controller2.Index = 0;
    }

    bool State;

    if (Controller2.Index <= 7)
    {
        State = Controller2.Buttons[Controller2.Index];
    }
    else
    {
        Controller2.Index = 8;
        State = 1;
    }

    Controller2.Index++;

    return 0x40 | State;
}
