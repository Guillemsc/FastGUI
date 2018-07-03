#include "Libs/SDL2/include/SDL.h"
#include "Libs/SDL2/include/SDL_syswm.h"
#include "Libs/SDL2/include/SDL_opengl.h"

#include "..\..\FastGUI.h"

void Fast_Init();
void Fast_NewFrame(SDL_Window* window);
void Fast_Render();
void FastProcessEvent(SDL_Event* ev);
void Fast_EndFrame();
void Fast_Quit();

namespace FastInternal
{
	int Fast_Internal_LoadTexture(Fuchar* data, FastVec2 size);
	void Fast_Internal_UnloadTexture();
}