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

bool FastVector4::Overlaps(const FastVector4 & vec)
{
	return false;
}

bool FastVector4::Contains(const FastVector4 & vec)
{
	return false;
}

void Fast::Init()
{
	if(fast_main != nullptr)
		fast_main = new FastInternal::FastMain();
}

void Fast::Quit()
{
	FAST_DEL(fast_main);
}

const char * Fast::GetVersion()
{
	return FASTGUI_VERSION;
}

FastInternal::FastMain::FastMain()
{
}

FastInternal::FastMain::~FastMain()
{
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
