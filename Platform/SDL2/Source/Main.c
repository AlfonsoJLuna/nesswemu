#include "Core.h"
#include <SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


bool Initialize_SDL(SDL_Window** Window, SDL_Renderer** Renderer, SDL_Texture** Texture)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }

    *Window = SDL_CreateWindow(
        VERSION,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        ((240 * 4) / 3) * 2,
        240 * 2,
        SDL_WINDOW_SHOWN |
        SDL_WINDOW_RESIZABLE);

    *Renderer = SDL_CreateRenderer(
        *Window,
        -1,
        SDL_RENDERER_SOFTWARE);

    *Texture = SDL_CreateTexture(
        *Renderer,
        SDL_PIXELFORMAT_RGB888,
        SDL_TEXTUREACCESS_TARGET,
        256,
        240);

    return 0;
}

bool Load_File(char* Path)
{
    FILE* File = fopen(Path, "rb");

    if (File == NULL)
	{
	    return 1;
    }

    fseek(File, 0, SEEK_END);
    size_t Size = ftell(File);
    rewind(File);

    uint8_t Buffer[Size];
    fread(Buffer, sizeof(uint8_t), Size, File);
    fclose(File);

    if (Core_Set_File(Buffer))
    {
        return 1;
    }

    Core_Power_Cycle();

    return 0;
}

bool Update_Input(bool* Buttons)
{
    SDL_Event Event;

    while (SDL_PollEvent(&Event))
    {
        switch (Event.type)
        {
            case SDL_QUIT:
                return 1;
            break;

            case SDL_KEYDOWN:
                switch (Event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_X:            Buttons[0] = 1;     break;
                    case SDL_SCANCODE_Z:            Buttons[1] = 1;     break;
                    case SDL_SCANCODE_BACKSPACE:    Buttons[2] = 1;     break;
                    case SDL_SCANCODE_RETURN:       Buttons[3] = 1;     break;
                    case SDL_SCANCODE_UP:           Buttons[4] = 1;     break;
                    case SDL_SCANCODE_DOWN:         Buttons[5] = 1;     break;
                    case SDL_SCANCODE_LEFT:         Buttons[6] = 1;     break;
                    case SDL_SCANCODE_RIGHT:        Buttons[7] = 1;     break;
                    default:                                            break;
                }
            break;

            case SDL_KEYUP:
                switch (Event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_X:            Buttons[0] = 0;     break;
                    case SDL_SCANCODE_Z:            Buttons[1] = 0;     break;
                    case SDL_SCANCODE_BACKSPACE:    Buttons[2] = 0;     break;
                    case SDL_SCANCODE_RETURN:       Buttons[3] = 0;     break;
                    case SDL_SCANCODE_UP:           Buttons[4] = 0;     break;
                    case SDL_SCANCODE_DOWN:         Buttons[5] = 0;     break;
                    case SDL_SCANCODE_LEFT:         Buttons[6] = 0;     break;
                    case SDL_SCANCODE_RIGHT:        Buttons[7] = 0;     break;
                    default:                                            break;
                }
            break;

            default:
            break;
        }
    }

    Core_Set_Input(Buttons);

    return 0;
}

void Render(SDL_Renderer* Renderer, SDL_Texture* Texture)
{
    uint32_t* Frame = Core_Get_Video_Frame();

    SDL_Rect Rect;
    Rect.w = 1;
    Rect.h = 1;

    SDL_SetRenderTarget(Renderer, Texture);

    for (int X = 0; X < 256; X++)
    {
        for (int Y = 0; Y < 240; Y++)
        {
            Rect.x = X;
            Rect.y = Y;
            SDL_RenderDrawRect(Renderer, &Rect);
            SDL_SetRenderDrawColor(Renderer,
                (Frame[256 * Y + X] >> 24) & 0xFF,
                (Frame[256 * Y + X] >> 16) & 0xFF,
                (Frame[256 * Y + X] >> 8) & 0xFF,
                0x00);
            SDL_RenderFillRect(Renderer, &Rect);
        }
    }

    SDL_SetRenderTarget(Renderer, NULL);
    SDL_RenderCopy(Renderer, Texture, NULL, NULL);
    SDL_RenderPresent(Renderer);
}

void Wait(double* LastTime)
{
    double FrameRate = 1000.0 / 60.0;

    double CurrentTime =
        SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();

    double BusyTime = (CurrentTime - *LastTime) * 1000.0;

    if (BusyTime < FrameRate)
    {
        SDL_Delay(FrameRate - BusyTime);
    }

    *LastTime =
        SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
}

void Finalize_SDL(SDL_Renderer* Renderer)
{
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    SDL_Window* Window = NULL;
    SDL_Renderer* Renderer = NULL;
    SDL_Texture* Texture = NULL;

    if (Initialize_SDL(&Window, &Renderer, &Texture))
    {
        return 1;
    }

    if (argc > 1)
    {
        if (Load_File(argv[1]))
        {
            return 1;
        }
    }
    else
    {
        if (Load_File("rom.nes"))
        {
            return 1;
        }
    }

    bool Quit = 0;
    bool Buttons[16] = {0};
    double LastTime = 0;

    while (!Quit)
    {
        Quit = Update_Input(Buttons);
        Core_Run();
        Render(Renderer, Texture);
        Wait(&LastTime);
    }

    Finalize_SDL(Renderer);

    return 0;
}
