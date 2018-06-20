#include "FastGUI.h"

static FastInternal::FastMain* fast_main = nullptr;

FastVector2::FastVector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

void FastVector2::operator+=(const FastVector2 & vec)
{
	x += vec.x;
	y += vec.y;
}

void FastVector2::operator-=(const FastVector2 & vec)
{
	x -= vec.x;
	y -= vec.y;
}

void FastVector2::operator*=(const FastVector2 & vec)
{
	x *= vec.x;
	y *= vec.y;
}

void FastVector2::operator/=(const FastVector2 & vec)
{
	if (vec.x != 0)
		x /= vec.x;

	if (vec.y != 0)
		y /= vec.y;
}

float FastVector2::Distance(const FastVector2 & vec)
{
	float dist_x = vec.x - x;
	float dist_y = vec.y - y;

	return sqrt(fabs((dist_x * dist_x) + (dist_y * dist_y)));
}

FastVector3::FastVector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void FastVector3::operator+=(const FastVector3 & vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

void FastVector3::operator-=(const FastVector3 & vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

void FastVector3::operator*=(const FastVector3 & vec)
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
}

void FastVector3::operator/=(const FastVector3 & vec)
{
	if (vec.x != 0)
		x /= vec.x;

	if (vec.y != 0)
		y /= vec.y;

	if (vec.z != 0)
		z /= vec.z;
}

float FastVector3::Distance(const FastVector3 & vec)
{
	float dist_x = vec.x - x;
	float dist_y = vec.y - y;
	float dist_z = vec.z - z;

	return sqrt(fabs((dist_x * dist_x) + (dist_y * dist_y) + (dist_z * dist_z)));
}

FastVector4::FastVector4(float _x, float _y, float _w, float _z)
{
	x = _x;
	y = _y;
	w = _w;
	z = _z;
}

void FastVector4::operator+=(const FastVector4 & vec)
{
	x += vec.x;
	y += vec.y;
	w += vec.w;
	z += vec.z;
}

void FastVector4::operator-=(const FastVector4 & vec)
{
	x -= vec.x;
	y -= vec.y;
	w -= vec.w;
	z -= vec.z;
}

void FastVector4::operator*=(const FastVector4 & vec)
{
	x *= vec.x;
	y *= vec.y;
	w *= vec.w;
	z *= vec.z;
}

void FastVector4::operator/=(const FastVector4 & vec)
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

FastVector2 FastRect::Center()
{
	return FastVector2(x + (w * 0.5f), y + (h * 0.5f));
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

void Fast::Init()
{
	if (fast_main == nullptr)
	{
		fast_main = new FastInternal::FastMain();
		fast_main->Start();
	}
}

void Fast::Quit()
{
	if (fast_main != nullptr)
		fast_main->CleanUp();

	FAST_DEL(fast_main);
}

const char * Fast::GetVersion()
{
	return FASTGUI_VERSION;
}

void Fast::PushID(const char * id)
{
}

void Fast::PopID()
{
}

FastInternal::FastMain::FastMain()
{
}

FastInternal::FastMain::~FastMain()
{
}

void FastInternal::FastMain::Start()
{
	io = new FastIO();
	style = new FastStyle();
	fonts = new FastFonts();
	draw = new FastDraw();
	hash = new FastHash();
}

void FastInternal::FastMain::CleanUp()
{
	FAST_DEL(io);
	FAST_DEL(style);
	FAST_DEL(fonts);
	FAST_DEL(draw);
	FAST_DEL(hash);
}

FastInternal::FastElement * FastInternal::FastMain::GetElement(std::string hash)
{
	return nullptr;
}

void FastInternal::FastMain::PushElement(FastElement * el)
{
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

FastRect::FastRect(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
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

FastInternal::FastElement::FastElement()
{
}

FastInternal::FastElement::~FastElement()
{
}

FastInternal::FastFonts::FastFonts()
{
}

FastInternal::FastFonts::~FastFonts()
{
}

FastInternal::FastDraw::FastDraw()
{
}

FastInternal::FastDraw::~FastDraw()
{
}

FastInternal::FastWindow::FastWindow()
{
}

FastInternal::FastWindow::~FastWindow()
{
}

FastInternal::FastHash::FastHash()
{
}

FastInternal::FastHash::~FastHash()
{
}
