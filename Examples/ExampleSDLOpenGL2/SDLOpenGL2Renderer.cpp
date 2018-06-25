#include "SDLOpenGL2Renderer.h"

#include "..\..\FastGUI.h"

void Fast_Init()
{
	FastInternal::Init();
}

void Fast_NewFrame()
{
	FastInternal::NewFrame();
}

void Fast_Render()
{
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
	glViewport(0, 0, 1280, 720);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0f, 1280, 720, 0.0f, -1.0f, +1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	std::vector<FastInternal::FastDrawShape> shapes = FastInternal::GetShapes();

	for (int i = 0; i < shapes.size(); ++i)
	{
		FastInternal::FastDrawShape curr_shape = shapes[i];

		glVertexPointer(curr_shape.VerticesSize(), GL_FLOAT, sizeof(float) * curr_shape.VerticesSize(), curr_shape.GetVertices());

		glTexCoordPointer(curr_shape.UvsSize(), GL_FLOAT, sizeof(float) * curr_shape.UvsSize(), curr_shape.GetUvs());

		//glBindTexture(GL_TEXTURE_2D, texture_id);

		glColorPointer(curr_shape.ColoursSize(), GL_FLOAT, sizeof(float) * curr_shape.ColoursSize(), curr_shape.GetColours());

		glDrawElements(GL_TRIANGLES, curr_shape.GetIndicesCount(), GL_UNSIGNED_INT, curr_shape.GetIndices());
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


//void FastProcessEvent(SDL_Event * ev)
//{
//}

void Fast_EndFrame()
{
	FastInternal::EndFrame();
}

void Fast_Quit()
{
	FastInternal::Quit();
}
