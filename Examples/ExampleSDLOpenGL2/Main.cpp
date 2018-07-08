#include <stdlib.h>

#include "Libs/SDL2/include/SDL.h"
#include "Libs/SDL2/include/SDL_opengl.h"

#pragma comment( lib, "Libs/SDL2/libx86/SDL2.lib" )
#pragma comment( lib, "Libs/SDL2/libx86/SDL2main.lib" )
#pragma comment (lib, "opengl32.lib")

#include "FastSDLOpenGL2Renderer.h"
#include "..\..\FastGUI.h"

int main(int argc, char ** argv)
{
	// Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		return -1;
	}

	// Setup window
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	SDL_Window *window = SDL_CreateWindow("ExampleSDLOpenGL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	if (glcontext == nullptr)
	{
		return 0;
	}

	SDL_GL_SetSwapInterval(0);

	// Initialize matrices
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearDepth(1.0f);

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	GLfloat LightModelAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightModelAmbient);

	GLfloat MaterialAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MaterialAmbient);

	GLfloat MaterialDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MaterialDiffuse);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	int size_x; int size_y;
	SDL_GetWindowSize(window, &size_x, &size_y);

	FastImpl::Init();

	FastInternal::FastWindow* win = Fast::Window();
	win->SetTitle("Transformations");
	win->SetPos(FastVec2(-400, 0));
	win->SetSize(FastVec2(400, 700));
	win->SetAnchor(FastVec2(1, 0));
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);
	win->AddElement(FastInternal::FastElementType::FAST_TEXT);

	//FastInternal::FastWindow* win2 = Fast::Window();
	//win2->SetPos(FastVec2(251, 10));
	//win2->SetTitle("Testing window");
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win2->AddElement(FastInternal::FastElementType::FAST_TEXT);

	//FastInternal::FastWindow* win3 = Fast::Window();
	//win3->SetPos(FastVec2(502, 10));
	//win3->SetTitle("Testing window");
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win3->AddElement(FastInternal::FastElementType::FAST_TEXT);

	//FastInternal::FastWindow* win4 = Fast::Window();
	//win4->SetPos(FastVec2(753, 10));
	//win4->SetTitle("Testing window");
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win4->AddElement(FastInternal::FastElementType::FAST_TEXT);

	//FastInternal::FastWindow* win5 = Fast::Window();
	//win5->SetPos(FastVec2(1004, 10));
	//win5->SetTitle("Testing window");
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win5->AddElement(FastInternal::FastElementType::FAST_TEXT);

	//FastInternal::FastWindow* win6 = Fast::Window();
	//win6->SetPos(FastVec2(1255, 10));
	//win6->SetTitle("Testing window");
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win6->AddElement(FastInternal::FastElementType::FAST_TEXT);

	//FastInternal::FastWindow* win7 = Fast::Window();
	//win7->SetPos(FastVec2(1506, 10));
	//win7->SetTitle("Testing window");
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);
	//win7->AddElement(FastInternal::FastElementType::FAST_TEXT);


	// Main loop
	bool done = false;
	while (!done)
	{
		FastImpl::NewFrame(window);

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			FastImpl::ProcessEvent(&event);

			if (event.type == SDL_QUIT)
				done = true;
		}
	
		// End render
		glViewport(0, 0, size_x, size_y);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		FastImpl::Render();

		SDL_GL_SwapWindow(window);
	}

	FastImpl::Quit();

	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}