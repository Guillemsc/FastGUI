#include "FastGUI.h"

static FastInternal::FastMain* fast_main = nullptr;

FastVec2::FastVec2()
{
	x = 0.0f;
	y = 0.0f;
}

FastVec2::FastVec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

FastVec2 FastVec2::operator+(const FastVec2 & vec)
{
	return FastVec2(x + vec.x, y + vec.y);
}

FastVec2 FastVec2::operator-(const FastVec2 & vec)
{
	return FastVec2(x - vec.x, y - vec.y);
}

FastVec2 FastVec2::operator*(const FastVec2 & vec)
{
	return FastVec2(x * vec.x, y * vec.y);
}

FastVec2 FastVec2::operator*(int val)
{
	return FastVec2(x * val, y *val);
}

FastVec2 FastVec2::operator*(float val)
{
	return FastVec2(x * val, y *val);
}

FastVec2 FastVec2::operator/(const FastVec2 & vec)
{
	FastVec2 ret;

	if (vec.x != 0)
		ret.x = x / vec.x;

	if (vec.y != 0)
		ret.y = y / vec.y;

	return ret;
}

void FastVec2::operator+=(const FastVec2 & vec)
{
	x += vec.x;
	y += vec.y;
}

void FastVec2::operator-=(const FastVec2 & vec)
{
	x -= vec.x;
	y -= vec.y;
}

void FastVec2::operator*=(const FastVec2 & vec)
{
	x *= vec.x;
	y *= vec.y;
}

void FastVec2::operator/=(const FastVec2 & vec)
{
	if (vec.x != 0)
		x /= vec.x;

	if (vec.y != 0)
		y /= vec.y;
}

float FastVec2::Distance(const FastVec2 & vec)
{
	float dist_x = vec.x - x;
	float dist_y = vec.y - y;

	return sqrt(fabs((dist_x * dist_x) + (dist_y * dist_y)));
}

FastVec3::FastVec3()
{
}

FastVec3::FastVec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

FastVec3 FastVec3::operator+(const FastVec3 & vec)
{
	return FastVec3(x + vec.x, y + vec.y, z + vec.z);
}

FastVec3 FastVec3::operator-(const FastVec3 & vec)
{
	return FastVec3(x - vec.x, y - vec.y, z - vec.z);
}

void FastVec3::operator+=(const FastVec3 & vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

void FastVec3::operator-=(const FastVec3 & vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

void FastVec3::operator*=(const FastVec3 & vec)
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
}

void FastVec3::operator/=(const FastVec3 & vec)
{
	if (vec.x != 0)
		x /= vec.x;

	if (vec.y != 0)
		y /= vec.y;

	if (vec.z != 0)
		z /= vec.z;
}

float FastVec3::Distance(const FastVec3 & vec)
{
	float dist_x = vec.x - x;
	float dist_y = vec.y - y;
	float dist_z = vec.z - z;

	return sqrt(fabs((dist_x * dist_x) + (dist_y * dist_y) + (dist_z * dist_z)));
}

FastVec4::FastVec4()
{
	x = 0;
	y = 0;
	w = 0;
	z = 0;
}

FastVec4::FastVec4(float _x, float _y, float _w, float _z)
{
	x = _x;
	y = _y;
	w = _w;
	z = _z;
}

FastVec4 FastVec4::operator+(const FastVec4 & vec)
{
	return FastVec4(x + vec.x, y + vec.y, w + vec.w, z + vec.z);
}

FastVec4 FastVec4::operator-(const FastVec4 & vec)
{
	return FastVec4(x - vec.x, y - vec.y, w - vec.w, z - vec.z);
}

void FastVec4::operator+=(const FastVec4 & vec)
{
	x += vec.x;
	y += vec.y;
	w += vec.w;
	z += vec.z;
}

void FastVec4::operator-=(const FastVec4 & vec)
{
	x -= vec.x;
	y -= vec.y;
	w -= vec.w;
	z -= vec.z;
}

void FastVec4::operator*=(const FastVec4 & vec)
{
	x *= vec.x;
	y *= vec.y;
	w *= vec.w;
	z *= vec.z;
}

void FastVec4::operator/=(const FastVec4 & vec)
{
	if (vec.x != 0)
		x /= vec.x;

	if (vec.y != 0)
		y /= vec.y;

	if (vec.w != 0)
		w = vec.w;

	if (vec.z != 0)
		z /= vec.z;
}

float FastRect::xw()
{
	return x + w;
}

float FastRect::yh()
{
	return y + h;
}

FastVec2 FastRect::Pos()
{
	return FastVec2(x, y);
}

FastVec2 FastRect::Size()
{
	return FastVec2(w, h);
}

FastVec2 FastRect::Center()
{
	return FastVec2(x + (w * 0.5f), y + (h * 0.5f));
}

bool FastRect::Overlaps(FastRect rect)
{
	if (xw() > rect.x && yh() > rect.y && x < rect.xw() && y < rect.yh())
		return true;
	return false;
}

bool FastRect::Contains(FastRect rec)
{
	if (x < rec.x && xw() > rec.xw() && y < rec.y && yh() > rec.yh())
		return true;
	return false;
}

bool FastRect::Contains(FastVec2 point)
{
	if (point.x >= x && point.x <= xw() && point.y >= y && point.y <= yh())
		return true;
	return false;
}

void FastRect::Scissor(FastRect rec)
{
	
}

FastColour::FastColour()
{
}

FastColour::FastColour(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
	a = 1.0f;
}

FastColour::FastColour(const FastVec4 & vec)
{
	r = vec.x;
	g = vec.y;
	b = vec.w;
	a = vec.z;
}

FastColour::FastColour(float _r, float _g, float _b, float _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

FastColour FastColour::operator+(const FastColour & vec)
{
	return FastColour(r + vec.r, g + vec.g, b + vec.b, a + vec.a);
}

FastColour FastColour::operator-(const FastColour & vec)
{
	return FastColour(r - vec.r, g - vec.g, b - vec.b, a - vec.a);
}

void FastColour::operator+=(const FastColour & vec)
{
	r += vec.r;
	g += vec.g;
	b += vec.b;
	a += vec.a;
}

void FastColour::operator-=(const FastColour & vec)
{
	r -= vec.r;
	g -= vec.g;
	b -= vec.b;
	a -= vec.a;
}

void FastColour::operator*=(const FastColour & vec)
{
	r *= vec.r;
	g *= vec.g;
	b *= vec.b;
	a *= vec.a;
}

void FastColour::operator/=(const FastColour & vec)
{
	if (vec.r != 0)
		r /= vec.r;

	if (vec.g != 0)
		g /= vec.g;

	if (vec.b != 0)
		b /= vec.b;

	if (vec.a != 0)
		a /= vec.a;
}

FastRect::FastRect()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

FastRect::FastRect(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

FastRect::FastRect(const FastVec4 & vec)
{
	x = vec.x;
	y = vec.y;
	w = vec.w;
	h = vec.z;
}

FastRect::FastRect(const FastVec2 & pos, const FastVec2 size)
{
	x = pos.x;
	y = pos.y;
	w = size.x;
	h = size.y;
}

FastBuffer::FastBuffer()
{
}

FastBuffer::FastBuffer(int size)
{
	SetSize(size);
}

FastBuffer::FastBuffer(int width, int height)
{
	SetSize(width, height);
}

void FastBuffer::SetSize(int _size)
{
	Clear();

	size = _size;

	buffer = new Fuchar[size];

	Reset();
}

void FastBuffer::SetSize(int _width, int _heigth)
{
	SetSize(_width * _heigth);

	width = _width;
	heigth = _heigth;
}

void FastBuffer::Reset()
{
	if (buffer != nullptr)
	{
		memset(buffer, 1, size);
	}
}

void FastBuffer::Clear()
{
	if (buffer != nullptr)
		FAST_DEL_ARRAY(buffer);

	buffer = nullptr;
}

void FastBuffer::AddData(int data_ptr_pos, Fuchar * data)
{
	Fuchar* tmp_buffer_ptr = buffer;

	tmp_buffer_ptr += data_ptr_pos;

	memcpy(tmp_buffer_ptr, data, sizeof(data));
}

Fuchar * FastBuffer::GetBufferData()
{
	return buffer;
}

bool FastBuffer::BufferHasData() const
{
	return buffer != nullptr;
}

int FastBuffer::GetWidth()
{
	return width;
}

int FastBuffer::GetHeight()
{
	return heigth;
}

int FastBuffer::GetSize()
{
	return size;
}

void FastBuffer::FlipUpsideDown()
{
	Fuint rows = heigth / 2; // Iterate only half the buffer to get a full flip
	Fuchar * tempRow = new Fuchar[width * sizeof(Fuchar)];

	for (unsigned rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		memcpy(tempRow, buffer + rowIndex * width, width * sizeof(Fuchar));
		memcpy(buffer + rowIndex * width, buffer + (heigth - rowIndex - 1) * width, width * sizeof(Fuchar));
		memcpy(buffer + (heigth - rowIndex - 1) * width, tempRow, width * sizeof(Fuchar));
	}

	FAST_DEL_ARRAY(tempRow);
}

const char * Fast::GetVersion()
{
	return FASTGUI_VERSION;
}

Fuint Fast::FPS()
{
	Fuint ret = 0.0f;

	if (FastInternal::CheckInited())
	{
		ret = fast_main->io->GetFps();
	}

	return ret;
}

void Fast::LoadFont(const char * filepath)
{
	if (FastInternal::CheckInited())
	{
		fast_main->fonts->LoadFont(filepath, 35, FastInternal::FastFontRange::FAST_FONT_RANGE_LATIN);
	}
}

FastInternal::FastWindow * Fast::Window()
{
	FastInternal::FastWindow* ret = nullptr;

	if (FastInternal::CheckInited())
	{
		ret = fast_main->elements->CreateWin();
	}

	return ret;
}

void FastInternal::Init()
{
	if (fast_main == nullptr)
	{
		fast_main = new FastInternal::FastMain();
		fast_main->Start();

		fast_main->style->SetDefaultStyle();	
	}
}

void FastInternal::Quit()
{
	if (fast_main != nullptr)
	{
		fast_main->CleanUp();
		FAST_DEL(fast_main);
	}
}

void FastInternal::NewFrame(FastVec2 window_size, FastVec2 mouse_pos, float delta_time)
{
	if (FastInternal::CheckInited())
	{
		fast_main->StartFrame();

		fast_main->io->AddNewFrame(delta_time);

		fast_main->io->SetViewportSize(window_size);
		fast_main->io->SetMousePos(mouse_pos);

		// Debug ---------------------------------------------------------

		fast_main->draw->DrawDebug();
	}
}

void FastInternal::SetLoadTexture(std::function<int(Fuchar*data, FastVec2 size)> _load_texture)
{
	fast_main->load_texture = _load_texture;
}

FastVec2 FastInternal::GetViewport()
{
	FastVec2 ret;

	if (FastInternal::CheckInited())
	{
		ret = fast_main->io->GetViewportSize();
	}

	return ret;
}

void FastInternal::SetKeyMapping(FastInternal::FastKeyMapping fast_key, Fuint maping_index)
{
	if (FastInternal::CheckInited())
	{
		fast_main->io->AddKeyMaping(fast_key, maping_index);
	}
}

FastVector<FastInternal::FastWindow*> FastInternal::GetWindows()
{
	FastVector<FastInternal::FastWindow*> ret;

	if (FastInternal::CheckInited())
	{
		ret = fast_main->elements->GetWindows();
	}

	return ret;
}

std::vector<FastInternal::FastDrawShape> FastInternal::GetDebugShapes()
{
	std::vector<FastInternal::FastDrawShape> ret;

	if (FastInternal::CheckInited())
	{
		ret = fast_main->draw->GetDebugShapes();
	}

	return ret;
}

FastInternal::FastMain::FastMain()
{
}

FastInternal::FastMain::~FastMain()
{
}

void FastInternal::FastMain::Start()
{
	io = new FastIO();			   AddModule(io);
	style = new FastStyle();	   AddModule(style);
	fonts = new FastFonts();	   AddModule(fonts);
	draw = new FastDraw();		   AddModule(draw); 
	elements = new FastElements(); AddModule(elements);

	for (std::vector<FastModule*>::iterator it = modules.begin(); it != modules.end(); ++it)
		(*it)->Start();
}

void FastInternal::FastMain::StartFrame()
{
	for (std::vector<FastModule*>::iterator it = modules.begin(); it != modules.end(); ++it)
		(*it)->StartFrame();
}

void FastInternal::FastMain::CleanUp()
{
	for (std::vector<FastModule*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->CleanUp();
		FAST_DEL(*it);
	}
	modules.clear();
}

void FastInternal::FastMain::AddModule(FastModule * mod)
{
	modules.push_back(mod);
}

bool FastInternal::CheckInited()
{
	if (fast_main == nullptr)
	{
		FAST_ASSERT(fast_main != nullptr, "Fast is not inited!");
		return false;
	}
	return true;
}

FastInternal::FastIO::FastIO()
{
}

FastInternal::FastIO::~FastIO()
{
}

void FastInternal::FastIO::Start()
{
}

void FastInternal::FastIO::CleanUp()
{
}

void FastInternal::FastIO::SetViewportSize(const FastVec2 & set)
{
	viewport_size = set;
}

FastVec2 FastInternal::FastIO::GetViewportSize() const
{
	return viewport_size;
}

bool FastInternal::FastIO::GetKeyDown(const FastKeyMapping & key) const
{
	return false;
}

void FastInternal::FastIO::SetMousePos(const FastVec2 & set)
{
	mouse_pos = set;
}

FastVec2 FastInternal::FastIO::GetMousePos()
{
	return mouse_pos;
}

void FastInternal::FastIO::AddKeyMaping(FastKeyMapping key, Fuint maped_key)
{
	key_maping[key] = maped_key;
}

void FastInternal::FastIO::AddNewFrame(float _delta_time)
{
	++frames_since_start;
	time_since_start_sec += _delta_time;
	delta_time = _delta_time;

	++frame_counter;
	frame_counter_ms += _delta_time;
	if (frame_counter_ms > 1.0f)
	{
		last_second_frames = frame_counter;
		frame_counter = 0;
		frame_counter_ms = 0.0f;
	}
}

Fuint FastInternal::FastIO::GetFramesSinceStart() const
{
	return frames_since_start;
}

float FastInternal::FastIO::GetTimeSinceStartSec() const
{
	return time_since_start_sec;
}

float FastInternal::FastIO::GetDeltaTime() const
{
	return delta_time;
}

Fuint FastInternal::FastIO::GetFps() const
{
	return last_second_frames;
}

float FastInternal::FastIO::GetAvgFps() const
{
	if (time_since_start_sec > 0)
		return (float)frames_since_start / time_since_start_sec;
	else
		return 0;
}

FastInternal::FastStyle::FastStyle()
{
}

FastInternal::FastStyle::~FastStyle()
{
}

void FastInternal::FastStyle::Start()
{
}

void FastInternal::FastStyle::CleanUp()
{
}

void FastInternal::FastStyle::SetDefaultStyle()
{
	def.alpha = 1.0f;

	def.physical.win_title_bar_height = 30;
	def.physical.win_x_padding = 6;
	def.physical.win_y_padding = 3;
	def.physical.widget_height = 40;
	def.physical.widget_x_padding = 6;
	def.physical.widget_y_padding = 3;
	def.physical.widgets_y_separation = 2;

	def.colours.win_bg = FastColour(0.2f, 0.2f, 0.2f);
	def.colours.win_title_bar = FastColour(0.35f, 0.07f, 0.07f);
	def.colours.text = FastColour(1, 1, 1);
	def.colours.widget_bg = FastColour(0.07f, 0.4f, 0.3f);
}

FastInternal::FastFonts::FastFonts()
{
}

FastInternal::FastFonts::~FastFonts()
{
}

void FastInternal::FastFonts::Start()
{
}

void FastInternal::FastFonts::CleanUp()
{
}

void FastInternal::FastFonts::LoadFont(const char * path, int font_size, FastFontRange range)
{
	FastFont* ret = nullptr;

	stbtt_fontinfo font_info;

	/* load font file */
	long size;
	unsigned char* fontBuffer;

	FILE* fontFile = nullptr;
	fopen_s(&fontFile, path, "rb");
	fseek(fontFile, 0, SEEK_END);
	size = ftell(fontFile); 
	fseek(fontFile, 0, SEEK_SET);

	fontBuffer = new unsigned char[size];

	fread(fontBuffer, size, 1, fontFile);
	fclose(fontFile);

	std::vector<FastVec2> glyph_ranges;

	std::vector<FastVec2> base_range = GetBaseGlyphsRanges();

	glyph_ranges.insert(glyph_ranges.end(), base_range.begin(), base_range.end());

	switch (range)
	{
	case FastInternal::FastFontRange::FAST_FONT_RANGE_LATIN:
	{
		std::vector<FastVec2> latin_range = GetLatinGlyphsRanges();

		glyph_ranges.insert(glyph_ranges.end(), latin_range.begin(), latin_range.end());

		break;
	}

	case FastInternal::FastFontRange::FAST_FONT_RANGE_KOREAN:
	{
		std::vector<FastVec2> korean_range = GetKoreanGlyphsRanges();

		glyph_ranges.insert(glyph_ranges.end(), korean_range.begin(), korean_range.end());

		break;
	}

	}

	if (stbtt_InitFont(&font_info, fontBuffer, stbtt_GetFontOffsetForIndex(fontBuffer, 0)))
	{
		if (curr_font != nullptr)
			FAST_DEL(curr_font);

		ret = new FastFont(font_info);

		int atlas_tex_w = 2048;
		int atlas_tex_h = 1024 * 1.0f; // 25
		FastBuffer buffer(atlas_tex_w, atlas_tex_h);

		if (font_size < 10)
			font_size = 10;
		if (font_size > 200)
			font_size = 200;

		int max_glyphs_to_generate = 600;

		float scale = stbtt_ScaleForPixelHeight(&font_info, font_size);

		int ascent, descent, lineGap;
		stbtt_GetFontVMetrics(&font_info, &ascent, &descent, &lineGap);

		float scaled_ascent = ascent * scale;
		float scaled_descent = descent * scale;
		float scaled_line_gap = lineGap *= scale;

		int total_h = ascent - descent;
		int scaled_total_h = scaled_ascent - scaled_descent;

		int curr_advance = 0;
		int line = 0;

		int glyphs_count = 0;
		for (int r = 0; r < glyph_ranges.size(); ++r)
		{
			FastVec2 curr_range = glyph_ranges[r];

			for (int i = curr_range.x; i < curr_range.y; ++i)
			{
				if (glyphs_count > max_glyphs_to_generate)
					break;

				int gliph_index = i;

				// Get Glyph bitmap size
				int x0, y0, x1, y1;
				stbtt_GetGlyphBitmapBox(&font_info, gliph_index, scale, scale, &x0, &y0, &x1, &y1);
				int glyph_bm_w = x1 - x0;
				int glyph_bm_h = y1 - y0;

				// Get Glyph advance values
				int advance;
				stbtt_GetGlyphHMetrics(&font_info, gliph_index, &advance, 0);
				advance *= scale;

				int kern_advance = stbtt_GetGlyphKernAdvance(&font_info, gliph_index, gliph_index + 1);
				kern_advance *= scale;

				int to_advance = advance + kern_advance;

				// Create a test advance to check glyph texture fiting
				int test_advance = curr_advance + to_advance;

				// Jump to new line if does not fit texture width
				if (test_advance + glyph_bm_w >= atlas_tex_w)
				{
					++line;
					curr_advance = 0;
				}

				// Calculate texture offset
				int to_down = y1 + (scaled_total_h - glyph_bm_h);

				int byteOffset = curr_advance + (line * (scaled_total_h + 1) * atlas_tex_w) + (to_down * atlas_tex_w);

				// Render glyph into texture
				stbtt_MakeGlyphBitmap(&font_info, buffer.GetBufferData() + byteOffset, glyph_bm_w, glyph_bm_h, atlas_tex_w, scale, scale, gliph_index);

				// Get uvs
				float x0_size_x = curr_advance;
				float x0_size_y = (line * (scaled_total_h)-scaled_descent);
				FastVec2 uvs_x0 = TexturePosToUV(FastVec2(atlas_tex_w, atlas_tex_h), FastVec2(x0_size_x, x0_size_y));

				float y1_size_x = curr_advance + glyph_bm_w;
				float y1_size_y = (line * scaled_total_h) + scaled_total_h - scaled_descent;
				FastVec2 uvs_y1 = TexturePosToUV(FastVec2(atlas_tex_w, atlas_tex_h), FastVec2(y1_size_x, y1_size_y));

				FastVec2 uvs_x1 = FastVec2(uvs_y1.x, uvs_x0.y);
				FastVec2 uvs_y0 = FastVec2(uvs_x0.x, uvs_y1.y);

				// Calculate x/y ratio
				float ratio_x_y = 1;
				float ratio_height_down = 0;

				if (scaled_total_h > 0)
					ratio_x_y = (float)glyph_bm_w / (float)scaled_total_h;

				// Advance
				curr_advance += to_advance + font_size * 0.15f;

				// Setup glyph
				FastGlyph glyph;
				glyph.uvs_x0 = uvs_x0;
				glyph.uvs_x1 = uvs_x1;
				glyph.uvs_y0 = uvs_y0;
				glyph.uvs_y1 = uvs_y1;
				glyph.ratio_x_y = ratio_x_y;

				ret->glyphs.push_back(glyph);

				++glyphs_count;
			}
		}

		buffer.FlipUpsideDown();

		ret->SetFontScale(scale);
		ret->texture_data = buffer.GetBufferData();
		ret->size.x = atlas_tex_w;
		ret->size.y = atlas_tex_h;
		ret->texture_id = fast_main->load_texture(ret->texture_data, ret->size);

		curr_font = ret;

		buffer.Clear();
	}

	// --------------------------------------
}

FastInternal::FastFont * FastInternal::FastFonts::GetCurrFont() const
{
	return curr_font;
}

FastVec2 FastInternal::FastFonts::TexturePosToUV(FastVec2 texture_size, FastVec2 pos)
{
	FastVec2 ret;

	float x_percentage = 0;
	float y_percentage = 0;

	if(texture_size.x != 0)
		x_percentage = (pos.x) / texture_size.x;

	if (texture_size.y != 0)
		y_percentage = (pos.y) / texture_size.y;

	ret.x = x_percentage;
	ret.y = 1 - y_percentage;

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetBaseGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(0, 32));

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetLatinGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(32, 255));

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetKoreanGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(32, 255));
	ret.push_back(FastVec2(12593, 12643));
	ret.push_back(FastVec2(44032, 55197));

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetChineseGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(32, 255));
	ret.push_back(FastVec2(12288, 12543));
	ret.push_back(FastVec2(12784, 12799));
	ret.push_back(FastVec2(65280, 65519));
	ret.push_back(FastVec2(19968, 40879));

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetJapaneseGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(32, 255));

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetCyrillicGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(32, 255));

	return ret;
}

std::vector<FastVec2> FastInternal::FastFonts::GetThaiGlyphsRanges()
{
	std::vector<FastVec2> ret;

	ret.push_back(FastVec2(32, 255));

	return ret;
}

FastInternal::FastFont::FastFont(stbtt_fontinfo _font_info)
{
	info = _font_info;
}

FastInternal::FastFont::~FastFont()
{
}

void FastInternal::FastFont::CleanUp()
{
}

FastInternal::FastGlyph FastInternal::FastFont::GetGlyphByChar(Fuchar c)
{
	FastGlyph ret;

	int index = 0;
	index = stbtt_FindGlyphIndex(&info, c);

	if (index < glyphs.size())
		ret = glyphs[index];
	else if (glyphs.size() > 0)
		ret = glyphs[0];

	return ret;
}

void FastInternal::FastFont::SetFontScale(float set)
{
	scale = set;
}

float FastInternal::FastFont::GetFontScale()
{
	return scale;
}

FastInternal::FastGlyph::FastGlyph()
{
}

FastInternal::FastDraw::FastDraw()
{
}

FastInternal::FastDraw::~FastDraw()
{
}

void FastInternal::FastDraw::Start()
{

}

void FastInternal::FastDraw::CleanUp()
{

}

void FastInternal::FastDraw::DrawDebug()
{
	debug_shapes.clear();

	fast_main->draw->StartShape();
	fast_main->draw->Quad(FastVec2(0, 0), FastVec2(35, 23), FastColour(0.1f, 0.1f, 0.1f));
	debug_shapes.push_back(fast_main->draw->FinishShape());

	fast_main->draw->StartShape();
	std::string frames = std::to_string(fast_main->io->GetFps());
	fast_main->draw->Text(FastVec2(2, 2), 20, fast_main->fonts->GetCurrFont(), frames, FastColour(1, 1, 1, 1));
	debug_shapes.push_back(fast_main->draw->FinishShape());

	fast_main->draw->StartShape();
	fast_main->draw->Quad(FastVec2(0, 2), FastVec2(100, 30), FastColour(0.1f, 0.1f, 0.1f));
	debug_shapes.push_back(fast_main->draw->FinishShape());

	fast_main->draw->StartShape();
	fast_main->draw->Text(FastVec2(0, 2), FastVec2(100, 30), fast_main->fonts->GetCurrFont(), frames, 
		FastDrawTextAlign::FAST_DRAW_TEXT_ALIGN_CENTER, true, FastColour(1, 1, 1, 1));
	debug_shapes.push_back(fast_main->draw->FinishShape());

	fast_main->draw->StartShape();
	fast_main->draw->Quad(FastVec2(500, 300), FastVec2(300, 300), FastColour(0.1f, 0.1f, 0.1f));
	debug_shapes.push_back(fast_main->draw->FinishShape());

	fast_main->draw->StartShape();
	fast_main->draw->Text(FastVec2(500, 300), FastVec2(300, 30), fast_main->fonts->GetCurrFont(), "This is a fucking test xd jajajaj",
		FastDrawTextAlign::FAST_DRAW_TEXT_ALIGN_CENTER, false, FastColour(1, 1, 1, 1));
	debug_shapes.push_back(fast_main->draw->FinishShape());

}

std::vector<FastInternal::FastDrawShape>& FastInternal::FastDraw::GetDebugShapes()
{
	return debug_shapes;
}

void FastInternal::FastDraw::StartShape()
{
	curr_shape = FastInternal::FastDrawShape();

	drawing_shape = true;
}

void FastInternal::FastDraw::ContinueShape(const FastDrawShape & shape)
{
	curr_shape = shape;

	drawing_shape = true;
}

FastInternal::FastDrawShape FastInternal::FastDraw::FinishShape()
{
	FastDrawShape ret;

	if (drawing_shape)
	{
		if (clipping_enabled)
			curr_shape.SetClippingRect(curr_clipping_rect);

		ret = curr_shape;
		curr_shape = FastInternal::FastDrawShape();

		drawing_shape = false;
	}
	else
		FAST_ASSERT(drawing_shape, "Shape can't be finished befor being created (Use StartShape function)");

	return ret;
}

void FastInternal::FastDraw::DisableClipping()
{
	clipping_enabled = false;
	curr_clipping_rect = FastRect();
}

void FastInternal::FastDraw::SetClipping(const FastRect & set)
{
	clipping_enabled = true;
	curr_clipping_rect = set;
}

void FastInternal::FastDraw::Line(FastVec2 start, FastVec2 end, FastColour colour)
{
}

void FastInternal::FastDraw::Quad(FastVec2 pos, FastVec2 size, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	curr_shape.AddPoint(FastVec2(min_x, min_y));
	curr_shape.AddPoint(FastVec2(min_x, max_y));
	curr_shape.AddPoint(FastVec2(max_x, max_y));
	curr_shape.AddPoint(FastVec2(max_x, min_y));
	curr_shape.Finish(colour);
}

void FastInternal::FastDraw::Circle(FastVec2 pos, float radius, FastColour colour)
{
	if (radius > 1)
	{
		int steps = 50;

		if (radius < 20)
			steps = radius;

		float angle_add = (float)360 / (float)(steps);
		float curr_angle = 0;

		curr_shape.AddPoint(FastVec2(pos.x, pos.y));

		for (int i = 0; i < steps + 1; ++i)
		{
			float curr_angle_rad = curr_angle * DEGTORAD;
			int x = cos(curr_angle_rad) * radius;
			int y = sin(curr_angle_rad) * radius;

			curr_angle -= angle_add;

			curr_shape.AddPoint(FastVec2(pos.x + x, pos.y + y));
		}

		curr_shape.Finish(colour);
	}
}

void FastInternal::FastDraw::CircleQuarter(FastVec2 pos, float radius, float starting_angle, FastColour colour)
{	
	if (radius > 1)
	{
		int steps = 10;

		if (radius < 20)
			steps = radius * 0.5f;

		float angle_add = (float)90 / (float)(steps);
		float curr_angle = -starting_angle;

		curr_shape.AddPoint(FastVec2(pos.x, pos.y));

		for (int i = 0; i < steps + 1; ++i)
		{
			float curr_angle_rad = curr_angle * DEGTORAD;
			int x = cos(curr_angle_rad) * radius;
			int y = sin(curr_angle_rad) * radius;

			curr_angle -= angle_add;

			curr_shape.AddPoint(FastVec2(pos.x + x, pos.y + y));
		}

		curr_shape.Finish(colour);
	}
}

void FastInternal::FastDraw::ImageQuad(FastVec2 pos, FastVec2 size, Fuint id)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	curr_shape.AddPoint(FastVec2(min_x, min_y));
	curr_shape.AddPoint(FastVec2(min_x, max_y));
	curr_shape.AddPoint(FastVec2(max_x, max_y));
	curr_shape.AddPoint(FastVec2(max_x, min_y));
	curr_shape.Finish(FastColour(1.0f, 0.1f, 0.9f, 1.0f));

	curr_shape.AddTextureId(id);
}

void FastInternal::FastDraw::DownTraingle(FastVec2 pos, float size, FastColour colour)
{
	FastVec2 point1 = pos;
	FastVec2 point2 = FastVec2(pos.x + (size * 0.5f), pos.y + size);
	FastVec2 point3 = FastVec2(pos.x + size, pos.y);

	curr_shape.AddPoint(point1);
	curr_shape.AddPoint(point2);
	curr_shape.AddPoint(point3);

	curr_shape.Finish(colour);
}

void FastInternal::FastDraw::RightTraingle(FastVec2 pos, float size, FastColour colour)
{
	FastVec2 point1 = pos;
	FastVec2 point2 = FastVec2(pos.x, pos.y + size);
	FastVec2 point3 = FastVec2(pos.x + size, pos.y + (size * 0.5f));

	curr_shape.AddPoint(point1);
	curr_shape.AddPoint(point2);
	curr_shape.AddPoint(point3);

	curr_shape.Finish(colour);
}

void FastInternal::FastDraw::RoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	if (round_radius > size.x * 0.5f)
		round_radius = size.x * 0.5f;

	if (round_radius > size.y * 0.5f)
		round_radius = size.y * 0.5f;

	CircleQuarter(FastVec2(min_x + round_radius, min_y + round_radius), round_radius, 90, colour);
	CircleQuarter(FastVec2(min_x + round_radius, max_y - round_radius), round_radius, 180, colour);
	CircleQuarter(FastVec2(max_x - round_radius, max_y - round_radius), round_radius, 270, colour);
	CircleQuarter(FastVec2(max_x - round_radius, min_y + round_radius), round_radius, 360, colour);

	Quad(FastVec2(min_x + round_radius, min_y), FastVec2((max_x - min_x) - (round_radius * 2), max_y - min_y), colour);
	Quad(FastVec2(min_x, min_y + round_radius), FastVec2(round_radius, (max_y - min_y) - (round_radius * 2)), colour);
	Quad(FastVec2(max_x - round_radius, min_y + round_radius), FastVec2(round_radius, (max_y - min_y) - (round_radius * 2)), colour);
}

void FastInternal::FastDraw::TopRoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	if (round_radius > size.x * 0.5f)
		round_radius = size.x * 0.5f;

	CircleQuarter(FastVec2(min_x + round_radius, min_y + round_radius), round_radius, 90, colour);
	CircleQuarter(FastVec2(max_x - round_radius, min_y + round_radius), round_radius, 360, colour);

	Quad(FastVec2(min_x + round_radius, min_y), FastVec2((max_x - min_x) - (round_radius * 2), round_radius), colour);
	Quad(FastVec2(min_x, min_y + round_radius), FastVec2(max_x - min_x, max_y - min_y - (round_radius)), colour);
}

void FastInternal::FastDraw::FontAtlas(FastVec2 pos, FastVec2 size, FastFont * font, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	curr_shape.AddPoint(FastVec2(min_x, min_y));
	curr_shape.AddPoint(FastVec2(min_x, max_y));
	curr_shape.AddPoint(FastVec2(max_x, max_y));
	curr_shape.AddPoint(FastVec2(max_x, min_y));

	curr_shape.AddTextureId(font->texture_id);
	curr_shape.Finish(colour);

	if (clipping_enabled)
		curr_shape.SetClippingRect(curr_clipping_rect);
}

void FastInternal::FastDraw::Text(FastVec2 pos, float size, FastFont* font, std::string text, FastColour colour)
{
	if (font != nullptr)
	{
		FastVec2 curr_pos = pos;

		for (int i = 0; i < text.size(); ++i)
		{
			Fuchar c = text[i];

			if (c != ' ')
			{
				FastGlyph glph = font->GetGlyphByChar(c);

				int word_width = size * glph.ratio_x_y;

				int min_x = curr_pos.x;
				int max_x = curr_pos.x + word_width;
				int min_y = curr_pos.y;
				int max_y = curr_pos.y + size;

				curr_shape.AddPoint(FastVec2(min_x, min_y));
				curr_shape.AddPoint(FastVec2(min_x, max_y));
				curr_shape.AddPoint(FastVec2(max_x, max_y));
				curr_shape.AddPoint(FastVec2(max_x, min_y));
				curr_shape.Finish(colour, FastVec4(glph.uvs_x0.x, glph.uvs_x0.y, glph.uvs_y1.x, glph.uvs_y1.y));

				curr_pos.x = max_x + (size * 0.11f);
			}
			else
				curr_pos.x += size * 0.25f;
		}

		curr_shape.AddTextureId(fast_main->fonts->GetCurrFont()->texture_id);

		if (clipping_enabled)
			curr_shape.SetClippingRect(curr_clipping_rect);
	}
}

void FastInternal::FastDraw::Text(FastVec2 pos, FastVec2 size, FastFont * font, std::string text, FastDrawTextAlign align, bool overflow, FastColour colour)
{
	if (font != nullptr)
	{
		FastVec2 curr_pos;

		std::vector<FastDrawTextLineInfo> lines_size_x;

		for (int i = 0; i < text.size(); ++i)
		{
			Fuchar c = text[i];

			if (c != ' ')
			{
				FastGlyph glph = font->GetGlyphByChar(c);

				int word_width = size.y * glph.ratio_x_y;

				int min_x = curr_pos.x;
				int max_x = curr_pos.x + word_width;
				int min_y = curr_pos.y;
				int max_y = curr_pos.y + size.y;

				curr_pos.x = max_x + (size.y * 0.11f);

				if (!overflow)
				{
					if (max_x > size.x)
					{
						FastDrawTextLineInfo line;
						line.x_size = size.x;
						line.max_word = i;
						lines_size_x.push_back(line);
						curr_pos.x = 0;
					}
				}
			}
			else
				curr_pos.x += size.y * 0.25f;
		}
		FastDrawTextLineInfo line;
		line.x_size = curr_pos.x;
		line.max_word = text.size() - 1;
		lines_size_x.push_back(line);

		curr_pos = pos;
		Fuint curr_line = 0;
		bool fist_time_advance = true;
		for (int i = 0; i < text.size(); ++i)
		{
			Fuchar c = text[i];

			if (c != ' ')
			{
				FastGlyph glph = font->GetGlyphByChar(c);

				int word_width = size.y * glph.ratio_x_y;

				int min_x = curr_pos.x;
				int min_y = curr_pos.y;

				if (fist_time_advance)
				{
					switch (align)
					{
					case FastDrawTextAlign::FAST_DRAW_TEXT_ALIGN_RIGHT:
						min_x += size.x - lines_size_x[curr_line].x_size;
						break;
					case FastDrawTextAlign::FAST_DRAW_TEXT_ALIGN_CENTER:
						min_x += (size.x - (lines_size_x[curr_line].x_size)) * 0.5f;
						break;
					}

					fist_time_advance = false;
				}

				int max_x = min_x + word_width;
				int max_y = min_y + size.y;

				curr_shape.AddPoint(FastVec2(min_x, min_y));
				curr_shape.AddPoint(FastVec2(min_x, max_y));
				curr_shape.AddPoint(FastVec2(max_x, max_y));
				curr_shape.AddPoint(FastVec2(max_x, min_y));
				curr_shape.Finish(colour, FastVec4(glph.uvs_x0.x, glph.uvs_x0.y, glph.uvs_y1.x, glph.uvs_y1.y));

				curr_pos.x = max_x + (size.y * 0.11f);

				if (lines_size_x[curr_line].max_word == i)
				{
					fist_time_advance = true;
					curr_pos.x = pos.x;
					curr_pos.y += size.y;
					++curr_line;
				}
			}
			else
				curr_pos.x += size.y * 0.25f;
		}

		curr_shape.AddTextureId(fast_main->fonts->GetCurrFont()->texture_id);

		if (clipping_enabled)
			curr_shape.SetClippingRect(curr_clipping_rect);
	}
}

void FastInternal::FastDraw::BezierQuad(FastVec2 pos, FastVec2 size, FastVec2 p1, FastVec2 p2)
{

}

FastInternal::FastDrawShape::FastDrawShape()
{
}

void FastInternal::FastDrawShape::AddPoint(FastVec2 point_pos)
{
	points.push_back(point_pos);

	if (points.size() == 1)
	{
		quad_size.x = point_pos.x;
		quad_size.w = point_pos.x;
		quad_size.y = point_pos.y;
		quad_size.z = point_pos.y;
	}
	else
	{
		if (point_pos.x < quad_size.x)
			quad_size.x = point_pos.x;

		if (point_pos.x > quad_size.w)
			quad_size.w = point_pos.x;

		if (point_pos.y < quad_size.y)
			quad_size.y = point_pos.y;

		if (point_pos.y > quad_size.z)
			quad_size.z = point_pos.y;
	}
	
}

void FastInternal::FastDrawShape::AddTextureId(Fuint id)
{
	texture_id = id;
}

void FastInternal::FastDrawShape::Finish(FastColour colour)
{
	if (points.size() >= 3)
	{		
		finished = true;

		// Vertices, Uvs, Colours

		int num_points = points.size();

		// Triangulize
		for (int i = 0; i < num_points; i++)
		{
			FastVec2 curr_point = points[i];

			vertices.push_back(curr_point.x);
			vertices.push_back(curr_point.y);
			vertices.push_back(0);

			// Color for vertices
			colours.push_back(colour.r);
			colours.push_back(colour.g);
			colours.push_back(colour.b);
			colours.push_back(colour.a);

			float x_uv = 0;
			float y_uv = 0;
			
			// Uvs for vertices
			float x_normalized = curr_point.x - quad_size.x;
			float y_normalized = curr_point.y - quad_size.y;

			float x_percentage = (x_normalized) / (quad_size.w - quad_size.x);
			float y_percentage = (y_normalized) / (quad_size.z - quad_size.y);

			x_uv = x_percentage;
			y_uv = 1 - y_percentage;
			
			uvs.push_back(x_uv);
			uvs.push_back(y_uv);

			if (i > 1)
			{
				// Indices for triangle
				indices.push_back(curr_indices_count);
				indices.push_back(curr_indices_count + i - 1);
				indices.push_back(curr_indices_count + i);
			}
		}

		//vertices_colour_uvs.insert(vertices_colour_uvs.end(), vertices.begin(), vertices.end());
		//vertices_colour_uvs.insert(vertices_colour_uvs.end(), colours.begin(), colours.end());
		//vertices_colour_uvs.insert(vertices_colour_uvs.end(), uvs.begin(), uvs.end());

		curr_indices_count += num_points;
		points.clear();
		quad_size = FastVec4();
		
		// -----------------------------------
	}

	points.clear();
}

void FastInternal::FastDrawShape::Finish(FastColour colour, FastVec4 range_uvs)
{
	if (points.size() >= 3)
	{
		int num_points = points.size();

		// Triangulize
		for (int i = 0; i < num_points; i++)
		{
			FastVec2 curr_point = points[i];

			vertices.push_back(curr_point.x);
			vertices.push_back(curr_point.y);
			vertices.push_back(0);

			// Color for vertices
			colours.push_back(colour.r);
			colours.push_back(colour.g);
			colours.push_back(colour.b);
			colours.push_back(colour.a);

			float ranged_x_uv = 0;
			float ranged_y_uv = 0;

			// Uvs for vertices
			float x_normalized = curr_point.x - quad_size.x;
			float y_normalized = curr_point.y - quad_size.y;

			float x_percentage = (x_normalized) / (quad_size.w - quad_size.x);
			float y_percentage = (y_normalized) / (quad_size.z - quad_size.y);

			float x_uv = x_percentage;
			float y_uv = y_percentage;

			if (x_uv > 0)
			{
				float diff = (1 * (range_uvs.w - range_uvs.x));
				ranged_x_uv = (x_uv * diff) / 1;
			}
			ranged_x_uv += range_uvs.x;

			if (y_uv > 0)
			{
				float diff = ((1 - range_uvs.z) - (1 - range_uvs.y));
				ranged_y_uv = (y_uv * diff) / 1;
			}
			ranged_y_uv = 1 - ranged_y_uv - (1 - range_uvs.y);

			uvs.push_back(ranged_x_uv);
			uvs.push_back(ranged_y_uv);

			if (i > 1)
			{
				// Indices for triangle
				indices.push_back(curr_indices_count);
				indices.push_back(curr_indices_count + i - 1);
				indices.push_back(curr_indices_count + i);
			}
		}

		//vertices_colour_uvs.insert(vertices_colour_uvs.end(), vertices.begin(), vertices.end());
		//vertices_colour_uvs.insert(vertices_colour_uvs.end(), colours.begin(), colours.end());
		//vertices_colour_uvs.insert(vertices_colour_uvs.end(), uvs.begin(), uvs.end());

		curr_indices_count += num_points;
		points.clear();
		quad_size = FastVec4();
		
		// -----------------------------------
	}
}

void FastInternal::FastDrawShape::Clear()
{
	finished = false;

	indices.clear();
	vertices.clear();
	colours.clear();
	uvs.clear();
	vertices_colour_uvs.clear();

	points.clear();
}

void FastInternal::FastDrawShape::SetClippingRect(const FastRect & rect)
{
	clipping_rect = rect;

	if (clipping_rect.w > 0 && clipping_rect.h > 0)
		uses_clipping_rect = true;
}

Fuint * FastInternal::FastDrawShape::GetIndicesPtr()
{
	Fuint* ret = nullptr;

	if (indices.size() > 0)
		ret = indices.data();
	
	return ret;
}

std::vector<Fuint> FastInternal::FastDrawShape::GetIndices()
{
	return indices;
}

Fuint FastInternal::FastDrawShape::GetIndicesCount()
{
	return indices.size();
}

float * FastInternal::FastDrawShape::GetVerticesPtr()
{
	float* ret = nullptr;

	if (vertices.size() > 0)
		ret = vertices.data();
	
	return ret;
}

std::vector<float> FastInternal::FastDrawShape::GetVertices()
{
	return vertices;
}

float * FastInternal::FastDrawShape::GetColoursPtr()
{
	float* ret = nullptr;

	if (colours.size() > 0)
		ret = colours.data();

	return ret;
}

std::vector<float> FastInternal::FastDrawShape::GetColours()
{
	return colours;
}

float * FastInternal::FastDrawShape::GetUvsPtr()
{
	float* ret = nullptr;

	if (uvs.size() > 0)
		ret = uvs.data();

	return ret;
}

std::vector<float> FastInternal::FastDrawShape::GetUvs()
{
	return uvs;
}

float * FastInternal::FastDrawShape::GetVerticesColourUvsPtr()
{
	float* ret = nullptr;

	if (vertices_colour_uvs.size() > 0)
		ret = vertices_colour_uvs.data();

	return ret;
}

std::vector<float> FastInternal::FastDrawShape::GetVerticesColoursUvs()
{
	return vertices_colour_uvs;
}

bool FastInternal::FastDrawShape::GetUsesClippingRect() const
{
	return uses_clipping_rect;
}

FastRect FastInternal::FastDrawShape::GetClippingRect() const
{
	return clipping_rect;
}

Fuint FastInternal::FastDrawShape::GetTextureId()
{
	return texture_id;
}

Fuint FastInternal::FastDrawShape::Offset()
{
	return 6;
}

Fuint FastInternal::FastDrawShape::VerticesOffset() const
{
	return 0;
}

Fuint FastInternal::FastDrawShape::VerticesSize() const
{
	return 3;
}

Fuint FastInternal::FastDrawShape::ColourOffset() const
{
	return 3;
}

Fuint FastInternal::FastDrawShape::ColoursSize() const
{
	return 4;
}

Fuint FastInternal::FastDrawShape::UvsOffset() const
{
	return 7;
}

Fuint FastInternal::FastDrawShape::UvsSize() const
{
	return 2;
}

FastInternal::FastElements::FastElements()
{
}

FastInternal::FastElements::~FastElements()
{
}

void FastInternal::FastElements::Start()
{
}

void FastInternal::FastElements::CleanUp()
{
}

void FastInternal::FastElements::StartFrame()
{
	if (hovered_window != nullptr)
	{
		hovered_window->SetHovered(true);
	}

	if (last_hovered_window != hovered_window && last_hovered_window != nullptr)
	{
		last_hovered_window->SetHovered(false);
	}

	if (hovered_element != nullptr)
	{
		hovered_element->SetHovered(true);
	}

	if (last_hovered_element != hovered_element && last_hovered_element != nullptr)
	{
		last_hovered_element->SetHovered(false);
	}

	last_hovered_window = hovered_window;
	last_hovered_element = hovered_element;
	hovered_window = nullptr;
	hovered_element = nullptr;
}

FastVector<FastInternal::FastWindow*>& FastInternal::FastElements::GetWindows()
{
	return windows;
}

FastInternal::FastWindow * FastInternal::FastElements::CreateWin()
{
	FastWindow* ret = nullptr;

	ret = new FastWindow(fast_main->style->def);
	ret->Start();

	windows.PushBack(ret);

	return ret;
}

FastInternal::FastElement::FastElement(const FastElementType& type, const FastStyleElements& default_style, FastWindow* _window)
{
	window = _window;
	style = default_style;
}

FastInternal::FastElement::~FastElement()
{
}

void FastInternal::FastElement::BaseUpdate()
{
	CheckMouseInput();
}

void FastInternal::FastElement::Start()
{
}

void FastInternal::FastElement::CleanUp()
{
}

FastVector<FastInternal::FastDrawShape>& FastInternal::FastElement::GetShapes()
{
	return draw_shapes;
}

void FastInternal::FastElement::SetStyle(const FastStyleElements & _style)
{
	style = _style;

	Redraw();
}

void FastInternal::FastElement::Redraw()
{
	needs_redraw = true;
}

void FastInternal::FastElement::CheckMouseInput()
{
	if (rect.Contains(fast_main->io->GetMousePos()))
		fast_main->elements->hovered_element = this;
}

void FastInternal::FastElement::SetHovered(bool set)
{
	if (hovered != set)
	{
		hovered = set;
		Redraw();
	}
}

FastInternal::FastWindow::FastWindow(const FastStyleElements& _default_style)
{
	style = _default_style; 
}

FastInternal::FastWindow::~FastWindow()
{
}

void FastInternal::FastWindow::Start()
{
	SetPos(FastVec2(10, 10));
	SetSize(FastVec2(250, 600));
	title_text = "Window";
}

void FastInternal::FastWindow::Update()
{
	RecalucalteRect();
	DoRedraw();
	CheckMouseInput();
}

void FastInternal::FastWindow::CleanUp()
{
}

FastInternal::FastElement * FastInternal::FastWindow::AddElement(const FastElementType & type)
{
	FastInternal::FastElement* ret = nullptr;

	switch (type)
	{
	case FastElementType::FAST_TEXT:
		ret = new FastElementText(fast_main->style->def, this);
		break;
	}

	if (ret != nullptr)
	{
		ret->Start();
		elements.PushBack(ret);

		RecalucalteRect();
		RecalculateElementsRect();
	}

	return ret;
}

void FastInternal::FastWindow::Redraw()
{
	needs_redraw = true;
}

FastVector<FastInternal::FastDrawShape>& FastInternal::FastWindow::GetShapes()
{
	return draw_shapes;
}

FastVector<FastInternal::FastElement*>& FastInternal::FastWindow::GetElements()
{
	return elements;
}

void FastInternal::FastWindow::SetStyle(const FastStyleElements & _style)
{
	style = _style;

	Redraw();
}

void FastInternal::FastWindow::SetTitle(std::string title)
{
	title_text = title;

	Redraw();
}

void FastInternal::FastWindow::SetUseTitle(bool set)
{
	uses_title_text = set;

	Redraw();
}

void FastInternal::FastWindow::SetPos(const FastVec2 & pos)
{
	local_pos.x = pos.x;
	local_pos.y = pos.y;
}

void FastInternal::FastWindow::SetAnchor(const FastVec2& _anchor)
{
	anchor = _anchor;

	if (anchor.x > 1)
		anchor.x = 1;
	if (anchor.y > 1)
		anchor.y = 1;
	if (anchor.x < 0)
		anchor.x = 0;
	if (anchor.y < 0)
		anchor.y = 0;
}

void FastInternal::FastWindow::SetSize(const FastVec2 & size)
{
	rect.w = size.x;
	rect.h = size.y;
}

FastRect FastInternal::FastWindow::GetWindowDrawingRect()
{
	FastRect ret = rect;

	if (uses_title_text)
	{
		ret.y += style.physical.win_title_bar_height;
		ret.h -= style.physical.win_title_bar_height;
	}
	return ret;
}

void FastInternal::FastWindow::RecalucalteRect()
{
	FastVec2 viewport = fast_main->io->GetViewportSize();

	rect.x = (viewport.x * anchor.x) + local_pos.x;
	rect.y = (viewport.y * anchor.y) + local_pos.y;

	if (rect.x != last_rect.x || rect.y != last_rect.y || rect.w != last_rect.w || rect.h != last_rect.h)
	{
		RecalculateElementsRect();

		Redraw();
	}

	last_rect = rect;
}

void FastInternal::FastWindow::RecalculateElementsRect()
{
	FastVec2 acumulated_height = GetWindowDrawingRect().Pos();

	//for (std::vector<FastElement*>::iterator it = elements.begin(); it != elements.end(); ++it)
	//{
	//	acumulated_height.y += (*it)->RecalucalteRect(acumulated_height).y;
	//	acumulated_height.y += style.physical.widgets_y_separation;
	//}

	for (int i = 0; i < elements.Size(); ++i)
	{
		acumulated_height.y += elements[i]->RecalucalteRect(acumulated_height).y;
		acumulated_height.y += style.physical.widgets_y_separation;
	}
}

void FastInternal::FastWindow::CheckMouseInput()
{
	if (rect.Contains(fast_main->io->GetMousePos()))
		fast_main->elements->hovered_window = this;
}

void FastInternal::FastWindow::SetHovered(bool set)
{
	if (hovered != set)
	{
		hovered = set;
		Redraw();
	}
}

void FastInternal::FastWindow::DoRedraw()
{
	if (needs_redraw)
	{
		draw_shapes.Clear();

		fast_main->draw->SetClipping(rect);

		FastVec2 pos = rect.Pos();
		FastVec2 size = rect.Size();
		FastRect drawing_rect = GetWindowDrawingRect();
		float x_padding = style.physical.win_x_padding;
		float y_padding = style.physical.win_y_padding;
		float bar_height = style.physical.win_title_bar_height;

		fast_main->draw->StartShape();
		FastColour bg_colour = style.colours.win_bg;
		bg_colour.a = style.alpha;
		fast_main->draw->Quad(drawing_rect.Pos(), drawing_rect.Size(), bg_colour);

		if(!uses_title_text)
			draw_shapes.PushBack(fast_main->draw->FinishShape());

		if (uses_title_text)
		{
			FastColour title_bar_colour = style.colours.win_title_bar;
			title_bar_colour.a = style.alpha;
			fast_main->draw->Quad(pos, FastVec2(size.x, bar_height), title_bar_colour);
			draw_shapes.PushBack(fast_main->draw->FinishShape());

			fast_main->draw->StartShape();
			FastColour title_text_colour = style.colours.text;
			title_text_colour.a = style.alpha;
			float text_height = bar_height - (y_padding * 2);
			fast_main->draw->Text(FastVec2(pos.x, pos.y + y_padding),
				FastVec2(size.x, text_height), fast_main->fonts->GetCurrFont(), title_text, 
				FastInternal::FastDrawTextAlign::FAST_DRAW_TEXT_ALIGN_CENTER, true, title_text_colour);
			draw_shapes.PushBack(fast_main->draw->FinishShape());
		}

		fast_main->draw->DisableClipping();
		
		needs_redraw = false;
	}
}

FastInternal::FastElementText::FastElementText(const FastStyleElements& default_style, FastWindow * window) 
	: FastElement(FastElementType::FAST_TEXT, default_style, window)
{
}

FastInternal::FastElementText::~FastElementText()
{
}

void FastInternal::FastElementText::Start()
{
	SetText("Text Widget");
}

void FastInternal::FastElementText::Update()
{
	DoRedraw();
}

void FastInternal::FastElementText::CleanUp()
{
}

void FastInternal::FastElementText::SetText(std::string txt)
{
	if (text != txt)
	{
		text = txt;
		DoRedraw();
	}
}

FastVec2 FastInternal::FastElementText::RecalucalteRect(const FastVec2 & starting_pos)
{
	rect.x = starting_pos.x;
	rect.y = starting_pos.y;
	rect.w = window->rect.w;
	rect.h = style.physical.widget_height;

	if (rect.x != last_rect.x || rect.y != last_rect.y || rect.w != last_rect.w || rect.h != last_rect.h)
		Redraw();

	last_rect = rect;

	return rect.Size();
}

void FastInternal::FastElementText::DoRedraw()
{
	if (needs_redraw)
	{
		draw_shapes.Clear();

		fast_main->draw->SetClipping(rect);

		FastVec2 pos = rect.Pos();
		FastVec2 size = rect.Size();
		float x_padding = style.physical.widget_x_padding;
		float y_padding = style.physical.widget_y_padding;

		fast_main->draw->StartShape();
		FastColour bg_colour = style.colours.widget_bg;
		if (hovered)
			bg_colour = FastColour(0.9, 0.9, 0.9);
		bg_colour.a = style.alpha;
		fast_main->draw->Quad(pos, size, bg_colour);
		draw_shapes.PushBack(fast_main->draw->FinishShape());

		fast_main->draw->StartShape();
		FastColour title_text_colour = style.colours.text;
		title_text_colour.a = style.alpha;
		float text_height = size.y - (y_padding * 2);
		fast_main->draw->Text(FastVec2(pos.x + x_padding, pos.y + y_padding),
			text_height, fast_main->fonts->GetCurrFont(), text, title_text_colour);
		draw_shapes.PushBack(fast_main->draw->FinishShape());

		fast_main->draw->DisableClipping();

		needs_redraw = false;
	}
}
