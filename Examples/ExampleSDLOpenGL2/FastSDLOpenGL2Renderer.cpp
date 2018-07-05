#include "FastSDLOpenGL2Renderer.h"

#include "..\..\FastGUI.h"

static double time_since_start_sec = 0;

void Fast_Init()
{
	FastInternal::Init();
	FastInternal::SetLoadTexture(FastInternal::Fast_Internal_LoadTexture);
	Fast::LoadFont("C://Windows//Fonts//Arial.ttf");

	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_TAB, SDLK_TAB);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_LEFT_ARROW, SDL_SCANCODE_LEFT);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_RIGHT_ARROW, SDL_SCANCODE_RIGHT);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_UP_ARROW, SDL_SCANCODE_UP);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_DOWN_ARROW, SDL_SCANCODE_DOWN);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_Z, SDLK_z);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_Y, SDLK_y);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_X, SDLK_x);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_V, SDLK_v);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_C, SDLK_c);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_PAGE_UP, SDL_SCANCODE_PAGEUP);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_PAGE_DOWN, SDL_SCANCODE_PAGEDOWN);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_ESCAPE, SDLK_ESCAPE);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_ENTER, SDLK_RETURN);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_DELETE, SDLK_DELETE);
	FastInternal::SetKeyMapping(FastInternal::FastKeyMapping::FAST_KEY_BACKSPACE, SDLK_BACKSPACE);
}

void Fast_NewFrame(SDL_Window* window)
{
	int size_x, size_y = 0;
	SDL_GetWindowSize(window, &size_x, &size_y);

	int mouse_x, mouse_y = 0;
	SDL_GetMouseState(&mouse_x, &mouse_y);

	Uint32 time = SDL_GetTicks();
	double current_time = time / 1000.0;
	float delta_dime = current_time - time_since_start_sec;
	time_since_start_sec = current_time;

	FastInternal::NewFrame(FastVec2(size_x, size_y), FastVec2(mouse_x, mouse_y), delta_dime);
}

void Fast_Render()
{
	FastVec2 viewport = FastInternal::GetViewport();

	GLint last_texture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
	GLint last_polygon_mode[2]; glGetIntegerv(GL_POLYGON_MODE, last_polygon_mode);
	GLint last_viewport[4]; glGetIntegerv(GL_VIEWPORT, last_viewport);
	GLint last_scissor_box[4]; glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_TRANSFORM_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

	// Setup viewport, orthographic projection matrix
	glViewport(0, 0, viewport.x, viewport.y);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0f, viewport.x, viewport.y, 0.0f, -1.0f, +1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	std::vector<FastInternal::FastDrawShape> shapes = FastInternal::GetShapes();

	for (int i = 0; i < shapes.size(); ++i)
	{
		FastInternal::FastDrawShape curr_shape = shapes[i];

		glVertexPointer(curr_shape.VerticesSize(), GL_FLOAT, sizeof(float) * curr_shape.VerticesSize(), curr_shape.GetVerticesPtr());

		glTexCoordPointer(curr_shape.UvsSize(), GL_FLOAT, sizeof(float) * curr_shape.UvsSize(), curr_shape.GetUvsPtr());

		if(curr_shape.GetTextureId() > 0)
			glBindTexture(GL_TEXTURE_2D, curr_shape.GetTextureId());

		glColorPointer(curr_shape.ColoursSize(), GL_FLOAT, sizeof(float) * curr_shape.ColoursSize(), curr_shape.GetColoursPtr());

		if (curr_shape.GetUsesClippingRect())
		{
			FastRect clipping = curr_shape.GetClippingRect();
			glScissor(clipping.x, viewport.y - clipping.yh(), clipping.w, viewport.y - clipping.y);
		}

		glDrawElements(GL_TRIANGLES, curr_shape.GetIndicesCount(), GL_UNSIGNED_INT, curr_shape.GetIndicesPtr());

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, (GLuint)last_texture);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPopAttrib();
	glPolygonMode(GL_FRONT, last_polygon_mode[0]); glPolygonMode(GL_BACK, last_polygon_mode[1]);
	glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
	glScissor(last_scissor_box[0], last_scissor_box[1], (GLsizei)last_scissor_box[2], (GLsizei)last_scissor_box[3]);
}

void FastProcessEvent(SDL_Event * ev)
{

}

void Fast_EndFrame()
{
	FastInternal::EndFrame();
}

void Fast_Quit()
{
	FastInternal::Quit();
}

int FastInternal::Fast_Internal_LoadTexture(Fuchar* data, FastVec2 size)
{
	int id = 0;

	// Upload texture to graphics system
	GLint last_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);

	glGenTextures(1, (GLuint*)&(id));
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	glPixelStorei( GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, size.x, size.y, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);

	// Restore state
	glBindTexture(GL_TEXTURE_2D, last_texture);

	return id;
}

void FastInternal::Fast_Internal_UnloadTexture()
{
}
