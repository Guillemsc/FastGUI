#include "FastGUI.h"

static FastInternal::FastMain* fast_main = nullptr;

FastVec2::FastVec2()
{
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

	size = _size * sizeof(Fuchar);

	buffer = new Fuchar[size];

	Reset();

	size = _size * sizeof(Fuchar);
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

void Fast::PushID(const char * id)
{
	if (FastInternal::Inited())
	{
		fast_main->creation->PushID(id);
	}
}

void Fast::PopID()
{
	if (FastInternal::Inited())
	{
		fast_main->creation->PopID();
	}
}

void Fast::Window(const char * name, FastVec2 pos)
{
	if (FastInternal::Inited())
	{
		bool created = false;

		FastInternal::FastWindow* win = (FastInternal::FastWindow*)fast_main->creation->HandleElement(name, FastInternal::FastElementType::FAST_WINDOW, created);

		if (win != nullptr)
		{
			if (created)
			{
				win->rect.x = pos.x;
				win->rect.y = pos.y;
				win->rect.w = 150;
				win->rect.h = 200;

				win->bg_colour = fast_main->style->colours.window_bg;
				win->bg_colour.a = fast_main->style->alpha;
			}

			win->Draw();
		}
	}
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
		fast_main->CleanUp();

	FAST_DEL(fast_main);
}

void FastInternal::NewFrame()
{
	if (FastInternal::Inited())
	{
		fast_main->draw->ClearShapes();

		//fast_main->draw->CircleQuarter(FastVec2(200, 200), 50, 0, 1, FastColour(1, 1, 1));

		//fast_main->draw->RoundedQuad(FastVec2(300, 300), FastVec2(300, 100), 10, 10, FastColour(0.2, 0.2, 0.2));
		////fast_main->draw->TopRoundedQuad(FastVec2(300, 300), FastVec2(300, 100), 150, 10, FastColour(0.3, 0.3, 0.3));

		//fast_main->draw->BezierQuad(FastVec2(200, 200), FastVec2(10, 10), FastVec2(0.8f, 0.0f), FastVec2(0.8f, 0.0f));

		//fast_main->draw->Circle(FastVec2(400, 200), 10, FastColour(0.2, 0.2, 0.2));

		fast_main->draw->FontAtlas(FastVec2(0, 0), FastVec2(1280, 720), fast_main->fonts->test_font, FastColour(1, 1, 1, 1));

		fast_main->draw->Text(FastVec2(10, 400), 100, fast_main->fonts->test_font, "Hola, me dic guillem @", FastColour(1, 1, 1, 1));
	}
}

void FastInternal::EndFrame()
{
	if (FastInternal::Inited())
	{
		fast_main->creation->RemoveDeadElements();
	}
}

void FastInternal::LoadFont(const char * filepath)
{
	if (FastInternal::Inited())
	{
		fast_main->fonts->LoadFont(filepath, 20, FastInternal::FastFontRange::FAST_FONT_RANGE_LATIN);
	}
}

void FastInternal::SetLoadTexture(std::function<int(Fuchar*data, FastVec2 size)> _load_texture)
{
	fast_main->load_texture = _load_texture;
}

std::vector<FastInternal::FastDrawShape> FastInternal::GetShapes()
{
	std::vector<FastInternal::FastDrawShape> ret;

	if (FastInternal::Inited())
	{
		ret = fast_main->draw->GetShapes();
	}

	return ret;
}

void FastInternal::ClearShapes()
{
	if (FastInternal::Inited())
	{
		fast_main->draw->ClearShapes();
	}
}

FastInternal::FastMain::FastMain()
{
}

FastInternal::FastMain::~FastMain()
{
}

void FastInternal::FastMain::Start()
{
	creation = new FastCreation();
	io = new FastIO();
	style = new FastStyle();
	fonts = new FastFonts();
	draw = new FastDraw();
	hash = new FastHash();
}

void FastInternal::FastMain::CleanUp()
{
	FAST_DEL(creation);
	FAST_DEL(io);
	FAST_DEL(style);
	FAST_DEL(fonts);
	FAST_DEL(draw);
	FAST_DEL(hash);
}

FastInternal::FastWindow * FastInternal::FastMain::GetCurrWindow()
{
	return nullptr;
}

bool FastInternal::Inited()
{
	if (fast_main == nullptr)
	{
		FAST_ASSERT(fast_main != nullptr, "Fast is not inited!");
		return false;
	}
	return true;
}

FastRect::FastRect()
{
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

FastInternal::FastCreation::FastCreation()
{
}

FastInternal::FastCreation::~FastCreation()
{
}

FastInternal::FastElement * FastInternal::FastCreation::HandleElement(const char * name, FastInternal::FastElementType type, bool& created)
{
	FastElement* ret = nullptr;

	std::string hash = fast_main->hash->GetMD5(name);

	ret = fast_main->creation->GetElement(hash);

	if (ret == nullptr)
	{
		ret = fast_main->creation->CreateElement(hash, type);
		created = true;
	}

	fast_main->creation->SetElementAlive(hash);

	return ret;
}

FastInternal::FastElement * FastInternal::FastCreation::CreateElement(std::string hash, FastInternal::FastElementType type)
{
	FastInternal::FastElement* ret = nullptr;

	switch (type)
	{
	case FastInternal::FAST_WINDOW:
		ret = new FastInternal::FastWindow(hash);
		break;
	case FastInternal::FAST_BUTTON:
		break;
	case FastInternal::FAST_TEXT:
		break;
	default:
		break;
	}

	if (ret != nullptr)
	{
		elements[hash] = ret;
	}

	return ret;
}

FastInternal::FastElement * FastInternal::FastCreation::GetElement(std::string hash)
{
	FastInternal::FastElement* ret = nullptr;

	ret = elements[hash];

	return ret;
}

void FastInternal::FastCreation::SetElementAlive(std::string hash)
{
	elements_alive.push_back(hash);
}

void FastInternal::FastCreation::RemoveDeadElements()
{
	for (std::map<std::string, FastElement*>::iterator it = elements.begin(); it != elements.end();)
	{
		bool found = false;

		for (std::vector<std::string>::iterator al = elements_alive.begin(); al != elements_alive.end(); ++al)
		{
			if ((*it).first == (*al))
			{
				found = true;
				elements_alive.erase(al);
				break;
			}
		}

		if (!found)
		{
			(*it).second->CleanUp();
			FAST_DEL((*it).second);
			it = elements.erase(it);
		}
		else
			++it;
	}

	elements_alive.clear();
}

void FastInternal::FastCreation::PushID(std::string id)
{
	ids.push_back(id);
}

void FastInternal::FastCreation::PopID()
{
	if (ids.size() > 0)
		ids.pop_back();
	else
		FAST_ASSERT(ids.size() > 0, "Trying to pop an id when there is no more ids to pop");
}

std::string FastInternal::FastCreation::GetCurrID() const
{
	std::string ret = "";

	for (std::vector<std::string>::const_iterator it = ids.begin(); it != ids.end(); ++it)
	{
		ret += (*it);
	}

	return ret;
}

FastInternal::FastIO::FastIO()
{
}

FastInternal::FastIO::~FastIO()
{
}

FastInternal::FastStyle::FastStyle()
{
}

FastInternal::FastStyle::~FastStyle()
{
}

void FastInternal::FastStyle::SetDefaultStyle()
{
	alpha = 1.0f;
	colours.window_bg = FastColour(0.2f, 0.2f, 0.2f);
}

FastInternal::FastElement::FastElement(std::string _hash, FastElementType _type)
{
	hash = _hash;
	type = _type;
}

FastInternal::FastElement::~FastElement()
{
}

void FastInternal::FastElement::CleanUp()
{
}

FastInternal::FastFonts::FastFonts()
{
}

FastInternal::FastFonts::~FastFonts()
{
}

FastInternal::FastFont* FastInternal::FastFonts::LoadFont(const char * path, int font_size, FastFontRange range)
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

		test_font = ret;

		//buffer.Clear();
	}

	// --------------------------------------

	return ret;
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

FastInternal::FastDraw::FastDraw()
{
}

FastInternal::FastDraw::~FastDraw()
{
}

void FastInternal::FastDraw::Line(FastVec2 start, FastVec2 end, FastColour colour)
{
}

void FastInternal::FastDraw::Quad(FastVec2 pos, FastVec2 size, FastColour colour)
{
	FastInternal::FastDrawShape shape;

	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	shape.AddPoint(FastVec2(min_x, min_y));
	shape.AddPoint(FastVec2(min_x, max_y));
	shape.AddPoint(FastVec2(max_x, max_y));
	shape.AddPoint(FastVec2(max_x, min_y));
	shape.Finish(colour);

	shapes.push_back(shape);
}

void FastInternal::FastDraw::Circle(FastVec2 pos, float radius, FastColour colour)
{
	if (radius > 1)
	{
		FastInternal::FastDrawShape shape;

		int steps = 50;

		if (radius < 20)
			steps = radius;

		float angle_add = (float)360 / (float)(steps);
		float curr_angle = 0;

		shape.AddPoint(FastVec2(pos.x, pos.y));

		for (int i = 0; i < steps + 1; ++i)
		{
			float curr_angle_rad = curr_angle * DEGTORAD;
			int x = cos(curr_angle_rad) * radius;
			int y = sin(curr_angle_rad) * radius;

			curr_angle -= angle_add;

			shape.AddPoint(FastVec2(pos.x + x, pos.y + y));
		}

		shape.Finish(colour);

		shapes.push_back(shape);
	}
}

void FastInternal::FastDraw::CircleQuarter(FastVec2 pos, float radius, float starting_angle, float roundness, FastColour colour)
{	
	if (radius > 1)
	{
		FastInternal::FastDrawShape shape;

		int steps = 10;

		if (radius < 20)
			steps = radius * 0.5f;

		float angle_add = (float)90 / (float)(steps);
		float curr_angle = -starting_angle;

		shape.AddPoint(FastVec2(pos.x, pos.y));

		for (int i = 0; i < steps + 1; ++i)
		{
			float curr_angle_rad = curr_angle * DEGTORAD;
			int x = cos(curr_angle_rad) * radius;
			int y = sin(curr_angle_rad) * radius;

			curr_angle -= angle_add;

			shape.AddPoint(FastVec2(pos.x + x, pos.y + y));
		}

		shape.Finish(colour);

		shapes.push_back(shape);
	}
}

void FastInternal::FastDraw::ImageQuad(FastVec2 pos, FastVec2 size, Fuint id)
{
	FastInternal::FastDrawShape shape;

	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	shape.AddPoint(FastVec2(min_x, min_y));
	shape.AddPoint(FastVec2(min_x, max_y));
	shape.AddPoint(FastVec2(max_x, max_y));
	shape.AddPoint(FastVec2(max_x, min_y));
	shape.Finish(FastColour(1.0f, 0.1f, 0.9f, 1.0f));

	shape.AddTextureId(id);

	shapes.push_back(shape);
}

void FastInternal::FastDraw::RoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, float roundness, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	if (round_radius > size.x * 0.5f)
		round_radius = size.x * 0.5f;

	if (round_radius > size.y * 0.5f)
		round_radius = size.y * 0.5f;

	CircleQuarter(FastVec2(min_x + round_radius, min_y + round_radius), round_radius, 90, roundness, colour);
	CircleQuarter(FastVec2(min_x + round_radius, max_y - round_radius), round_radius, 180, roundness, colour);
	CircleQuarter(FastVec2(max_x - round_radius, max_y - round_radius), round_radius, 270, roundness, colour);
	CircleQuarter(FastVec2(max_x - round_radius, min_y + round_radius), round_radius, 360, roundness, colour);

	Quad(FastVec2(min_x + round_radius, min_y), FastVec2((max_x - min_x) - (round_radius * 2), max_y - min_y), colour);
	Quad(FastVec2(min_x, min_y + round_radius), FastVec2(round_radius, (max_y - min_y) - (round_radius * 2)), colour);
	Quad(FastVec2(max_x - round_radius, min_y + round_radius), FastVec2(round_radius, (max_y - min_y) - (round_radius * 2)), colour);
}

void FastInternal::FastDraw::TopRoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, float roundness, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	if (round_radius > size.x * 0.5f)
		round_radius = size.x * 0.5f;

	CircleQuarter(FastVec2(min_x + round_radius, min_y + round_radius), round_radius, 90, roundness, colour);
	CircleQuarter(FastVec2(max_x - round_radius, min_y + round_radius), round_radius, 360, roundness, colour);

	Quad(FastVec2(min_x + round_radius, min_y), FastVec2((max_x - min_x) - (round_radius * 2), round_radius), colour);
	Quad(FastVec2(min_x, min_y + round_radius), FastVec2(max_x - min_x, max_y - min_y), colour);
}

void FastInternal::FastDraw::FontAtlas(FastVec2 pos, FastVec2 size, FastFont * font, FastColour colour)
{
	int min_x = pos.x;
	int max_x = pos.x + size.x;
	int min_y = pos.y;
	int max_y = pos.y + size.y;

	FastDrawShape shape;

	shape.AddPoint(FastVec2(min_x, min_y));
	shape.AddPoint(FastVec2(min_x, max_y));
	shape.AddPoint(FastVec2(max_x, max_y));
	shape.AddPoint(FastVec2(max_x, min_y));

	shape.AddTextureId(font->texture_id);
	shape.Finish(colour);

	shapes.push_back(shape);
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

				FastDrawShape shape;

				shape.AddPoint(FastVec2(min_x, min_y));
				shape.AddPoint(FastVec2(min_x, max_y));
				shape.AddPoint(FastVec2(max_x, max_y));
				shape.AddPoint(FastVec2(max_x, min_y));
				shape.Finish(colour, FastVec4(glph.uvs_x0.x, glph.uvs_x0.y, glph.uvs_y1.x, glph.uvs_y1.y));

				shape.AddTextureId(fast_main->fonts->test_font->texture_id);

				shapes.push_back(shape);

				curr_pos.x = max_x + (size * 0.11f);
			}
			else
				curr_pos.x += size * 0.25f;
		}
	}
}

void FastInternal::FastDraw::BezierQuad(FastVec2 pos, FastVec2 size, FastVec2 p1, FastVec2 p2)
{
	/*FastInternal::FastDrawShape shape;

	std::vector<FastVec2> points; points.push_back(p1); points.push_back(p2);

	for (float t = 0; t < 1; t += 0.6f)
	{
		int i = points.size() - 1;
		while (i > 0)
		{			
			for (int k = 0; k < i; k++)
			{
				float point_x = points[k].x + t * (points[k + 1].x - points[k].x);
				float point_y = points[k].y + t * (points[k + 1].y - points[k].y);

				shape.AddPoint(FastVec2(pos.x + point_x, pos.y + point_y));
			}
			--i;
		}
	}
	
	shape.Finish(FastColour(1, 1, 1, 1));
	shapes.push_back(shape);*/
}

std::vector<FastInternal::FastDrawShape> FastInternal::FastDraw::GetShapes() const
{
	return shapes;
}

void FastInternal::FastDraw::ClearShapes()
{
	shapes.clear();
}

FastInternal::FastWindow::FastWindow(std::string hash) : FastElement(hash, FastElementType::FAST_WINDOW)
{
}

FastInternal::FastWindow::~FastWindow()
{
}

void FastInternal::FastWindow::Draw()
{
	fast_main->draw->RoundedQuad(rect.Pos(), rect.Size(), 10, 10, bg_colour);
	fast_main->draw->TopRoundedQuad(rect.Pos(), FastVec2(rect.Size().x, 10), 10, 0, FastColour(0.4, 0.4, 0.4, 1));
	fast_main->draw->Text(FastVec2(rect.Pos().x + 10, rect.Pos().y + 3), 15, fast_main->fonts->test_font, "Window text", FastColour(1, 1, 1, 1));
}

FastInternal::FastHash::FastHash()
{
	std::string md1 = GetMD5("asdasdasdasd");
	std::string md2 = GetMD5("hi");
}

FastInternal::FastHash::~FastHash()
{
}

std::string FastInternal::FastHash::GetMD5(std::string text)
{
	init();
	update(text.c_str(), text.length());
	finalize();
	return hexdigest();
}

// F, G, H and I are basic MD5 functions.
Fuint FastInternal::FastHash::F(uint4 x, uint4 y, uint4 z) {
	return x & y | ~x&z;
}

Fuint FastInternal::FastHash::G(uint4 x, uint4 y, uint4 z) {
	return x & z | y & ~z;
}

Fuint FastInternal::FastHash::H(uint4 x, uint4 y, uint4 z) {
	return x ^ y^z;
}

Fuint FastInternal::FastHash::I(uint4 x, uint4 y, uint4 z) {
	return y ^ (x | ~z);
}

// rotate_left rotates x left n bits.
Fuint FastInternal::FastHash::rotate_left(uint4 x, int n) {
	return (x << n) | (x >> (32 - n));
}

// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
// Rotation is separate from addition to prevent recomputation.
void FastInternal::FastHash::FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + F(b, c, d) + x + ac, s) + b;
}

void FastInternal::FastHash::GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + G(b, c, d) + x + ac, s) + b;
}

void FastInternal::FastHash::HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + H(b, c, d) + x + ac, s) + b;
}

void FastInternal::FastHash::II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac) {
	a = rotate_left(a + I(b, c, d) + x + ac, s) + b;
}

// decodes input (unsigned char) into output (uint4). Assumes len is a multiple of 4.
void FastInternal::FastHash::decode(uint4 output[], const uint1 input[], size_type len)
{
	for (unsigned int i = 0, j = 0; j < len; i++, j += 4)
		output[i] = ((uint4)input[j]) | (((uint4)input[j + 1]) << 8) |
		(((uint4)input[j + 2]) << 16) | (((uint4)input[j + 3]) << 24);
}

//////////////////////////////

// encodes input (uint4) into output (unsigned char). Assumes len is
// a multiple of 4.
void FastInternal::FastHash::encode(uint1 output[], const uint4 input[], size_type len)
{
	for (size_type i = 0, j = 0; j < len; i++, j += 4) {
		output[j] = input[i] & 0xff;
		output[j + 1] = (input[i] >> 8) & 0xff;
		output[j + 2] = (input[i] >> 16) & 0xff;
		output[j + 3] = (input[i] >> 24) & 0xff;
	}
}

// apply MD5 algo on a block
void FastInternal::FastHash::transform(const uint1 block[blocksize])
{
	uint4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
	decode(x, block, blocksize);

	/* Round 1 */
	FF(a, b, c, d, x[0], S11, 0xd76aa478); /* 1 */
	FF(d, a, b, c, x[1], S12, 0xe8c7b756); /* 2 */
	FF(c, d, a, b, x[2], S13, 0x242070db); /* 3 */
	FF(b, c, d, a, x[3], S14, 0xc1bdceee); /* 4 */
	FF(a, b, c, d, x[4], S11, 0xf57c0faf); /* 5 */
	FF(d, a, b, c, x[5], S12, 0x4787c62a); /* 6 */
	FF(c, d, a, b, x[6], S13, 0xa8304613); /* 7 */
	FF(b, c, d, a, x[7], S14, 0xfd469501); /* 8 */
	FF(a, b, c, d, x[8], S11, 0x698098d8); /* 9 */
	FF(d, a, b, c, x[9], S12, 0x8b44f7af); /* 10 */
	FF(c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
	FF(b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
	FF(a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
	FF(d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
	FF(c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
	FF(b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

											/* Round 2 */
	GG(a, b, c, d, x[1], S21, 0xf61e2562); /* 17 */
	GG(d, a, b, c, x[6], S22, 0xc040b340); /* 18 */
	GG(c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
	GG(b, c, d, a, x[0], S24, 0xe9b6c7aa); /* 20 */
	GG(a, b, c, d, x[5], S21, 0xd62f105d); /* 21 */
	GG(d, a, b, c, x[10], S22, 0x2441453); /* 22 */
	GG(c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
	GG(b, c, d, a, x[4], S24, 0xe7d3fbc8); /* 24 */
	GG(a, b, c, d, x[9], S21, 0x21e1cde6); /* 25 */
	GG(d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
	GG(c, d, a, b, x[3], S23, 0xf4d50d87); /* 27 */
	GG(b, c, d, a, x[8], S24, 0x455a14ed); /* 28 */
	GG(a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
	GG(d, a, b, c, x[2], S22, 0xfcefa3f8); /* 30 */
	GG(c, d, a, b, x[7], S23, 0x676f02d9); /* 31 */
	GG(b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

											/* Round 3 */
	HH(a, b, c, d, x[5], S31, 0xfffa3942); /* 33 */
	HH(d, a, b, c, x[8], S32, 0x8771f681); /* 34 */
	HH(c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
	HH(b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
	HH(a, b, c, d, x[1], S31, 0xa4beea44); /* 37 */
	HH(d, a, b, c, x[4], S32, 0x4bdecfa9); /* 38 */
	HH(c, d, a, b, x[7], S33, 0xf6bb4b60); /* 39 */
	HH(b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
	HH(a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
	HH(d, a, b, c, x[0], S32, 0xeaa127fa); /* 42 */
	HH(c, d, a, b, x[3], S33, 0xd4ef3085); /* 43 */
	HH(b, c, d, a, x[6], S34, 0x4881d05); /* 44 */
	HH(a, b, c, d, x[9], S31, 0xd9d4d039); /* 45 */
	HH(d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
	HH(c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
	HH(b, c, d, a, x[2], S34, 0xc4ac5665); /* 48 */

										   /* Round 4 */
	II(a, b, c, d, x[0], S41, 0xf4292244); /* 49 */
	II(d, a, b, c, x[7], S42, 0x432aff97); /* 50 */
	II(c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
	II(b, c, d, a, x[5], S44, 0xfc93a039); /* 52 */
	II(a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
	II(d, a, b, c, x[3], S42, 0x8f0ccc92); /* 54 */
	II(c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
	II(b, c, d, a, x[1], S44, 0x85845dd1); /* 56 */
	II(a, b, c, d, x[8], S41, 0x6fa87e4f); /* 57 */
	II(d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
	II(c, d, a, b, x[6], S43, 0xa3014314); /* 59 */
	II(b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
	II(a, b, c, d, x[4], S41, 0xf7537e82); /* 61 */
	II(d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
	II(c, d, a, b, x[2], S43, 0x2ad7d2bb); /* 63 */
	II(b, c, d, a, x[9], S44, 0xeb86d391); /* 64 */

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;

	// Zeroize sensitive information.
	memset(x, 0, sizeof x);
}

// MD5 block update operation. Continues an MD5 message-digest
// operation, processing another message block
void FastInternal::FastHash::update(const unsigned char* input, size_type length)
{
	// compute number of bytes mod 64
	size_type index = count[0] / 8 % blocksize;

	// Update number of bits
	if ((count[0] += (length << 3)) < (length << 3))
		count[1]++;
	count[1] += (length >> 29);

	// number of bytes we need to fill in buffer
	size_type firstpart = 64 - index;

	size_type i;

	// transform as many times as possible.
	if (length >= firstpart)
	{
		// fill buffer first, transform
		memcpy(&buffer[index], input, firstpart);
		transform(buffer);

		// transform chunks of blocksize (64 bytes)
		for (i = firstpart; i + blocksize <= length; i += blocksize)
			transform(&input[i]);

		index = 0;
	}
	else
		i = 0;

	// buffer remaining input
	memcpy(&buffer[index], &input[i], length - i);
}

// for convenience provide a verson with signed char
void FastInternal::FastHash::update(const char* input, size_type length)
{
	update((const unsigned char*)input, length);
}

// MD5 finalization. Ends an MD5 message-digest operation, writing the
// the message digest and zeroizing the context.
void FastInternal::FastHash::finalize()
{
	static unsigned char padding[64] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	if (!finalized) 
	{
		// Save number of bits
		unsigned char bits[8];
		encode(bits, count, 8);

		// pad out to 56 mod 64.
		size_type index = count[0] / 8 % 64;
		size_type padLen = (index < 56) ? (56 - index) : (120 - index);
		update(padding, padLen);

		// Append length (before padding)
		update(bits, 8);

		// Store state in digest
		encode(digest, state, 16);

		// Zeroize sensitive information.
		memset(buffer, 0, sizeof buffer);
		memset(count, 0, sizeof count);

		finalized = true;
	}
}

void FastInternal::FastHash::init()
{
	finalized = false;

	count[0] = 0;
	count[1] = 0;

	// load magic initialization constants.
	state[0] = 0x67452301;
	state[1] = 0xefcdab89;
	state[2] = 0x98badcfe;
	state[3] = 0x10325476;
}

// return hex representation of digest as string
std::string FastInternal::FastHash::hexdigest() const
{
	if (!finalized)
		return "";

	char buf[33];
	for (int i = 0; i<16; i++)
		sprintf_s(buf + i * 2, 3, "%02x", digest[i]);
	buf[32] = 0;

	return std::string(buf);
}

FastInternal::FastDrawShape::FastDrawShape()
{
}

void FastInternal::FastDrawShape::AddPoint(FastVec2 point_pos)
{
	if (!finished)
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
}

void FastInternal::FastDrawShape::AddTextureId(Fuint id)
{
	texture_id = id;
}

void FastInternal::FastDrawShape::Finish(FastColour colour)
{
	if (points.size() >= 3)
	{
		// Calc vertext, indices and color
		if (points.size() >= 3 && !finished)
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
					indices.push_back(0);
					indices.push_back(i - 1);
					indices.push_back(i);
				}
			}

			vertices_colour_uvs.insert(vertices_colour_uvs.end(), vertices.begin(), vertices.end());
			vertices_colour_uvs.insert(vertices_colour_uvs.end(), colours.begin(), colours.end());
			vertices_colour_uvs.insert(vertices_colour_uvs.end(), uvs.begin(), uvs.end());
		}
		// -----------------------------------
	}
}

void FastInternal::FastDrawShape::Finish(FastColour colour, FastVec4 range_uvs)
{
	if (points.size() >= 3)
	{
		// Calc vertext, indices and color
		if (points.size() >= 3 && !finished)
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
					indices.push_back(0);
					indices.push_back(i - 1);
					indices.push_back(i);
				}
			}

			vertices_colour_uvs.insert(vertices_colour_uvs.end(), vertices.begin(), vertices.end());
			vertices_colour_uvs.insert(vertices_colour_uvs.end(), colours.begin(), colours.end());
			vertices_colour_uvs.insert(vertices_colour_uvs.end(), uvs.begin(), uvs.end());
		}
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

Fuint * FastInternal::FastDrawShape::GetIndices()
{
	Fuint* ret = nullptr;

	if (indices.size() > 0)
		ret = indices.data();
	
	return ret;
}

Fuint FastInternal::FastDrawShape::GetIndicesCount()
{
	return indices.size();
}

float * FastInternal::FastDrawShape::GetVertices()
{
	float* ret = nullptr;

	if (vertices.size() > 0)
		ret = vertices.data();
	
	return ret;
}

float * FastInternal::FastDrawShape::GetColours()
{
	float* ret = nullptr;

	if (colours.size() > 0)
		ret = colours.data();

	return ret;
}

float * FastInternal::FastDrawShape::GetUvs()
{
	float* ret = nullptr;

	if (uvs.size() > 0)
		ret = uvs.data();

	return ret;
}

float * FastInternal::FastDrawShape::GetVerticesColourUvs()
{
	float* ret = nullptr;

	if (vertices_colour_uvs.size() > 0)
		ret = vertices_colour_uvs.data();

	return ret;
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

FastInternal::FastFont::FastFont(stbtt_fontinfo _font_info)
{
	info = _font_info;
}

FastInternal::FastFont::~FastFont()
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
