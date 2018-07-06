#include "Libs/SDL2/include/SDL.h"
#include "Libs/SDL2/include/SDL_syswm.h"
#include "Libs/SDL2/include/SDL_opengl.h"

#include "..\..\FastGUI.h"

namespace FastImpl
{
	void Init();
	void NewFrame(SDL_Window* window);
	void Render();
	void ProcessEvent(SDL_Event* ev);
	void Quit();
}

namespace FastInternal
{
	int LoadTexture(Fuchar* data, FastVec2 size);
	void UnloadTexture();
	void RenderShape(FastInternal::FastDrawShape shape);
}