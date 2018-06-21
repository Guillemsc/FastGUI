#include "FastGUI.h"

static FastInternal::FastMain* fast_main = nullptr;

FastVec2::FastVec2(float _x, float _y)
{
	x = _x;
	y = _y;
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

FastVec3::FastVec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
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

FastVec4::FastVec4(float _x, float _y, float _w, float _z)
{
	x = _x;
	y = _y;
	w = _w;
	z = _z;
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

void FastInternal::Init()
{
	if (fast_main == nullptr)
	{
		fast_main = new FastInternal::FastMain();
		fast_main->Start();
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

	}
}

void FastInternal::EndFrame()
{
	if (FastInternal::Inited())
	{
		fast_main->creation->RemoveDeadElements();
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

FastRect::FastRect(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

FastInternal::FastCreation::FastCreation()
{
}

FastInternal::FastCreation::~FastCreation()
{
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

FastInternal::FastDraw::FastDraw()
{
}

FastInternal::FastDraw::~FastDraw()
{
}

FastInternal::FastWindow::FastWindow(std::string hash) : FastElement(hash, FastElementType::FAST_WINDOW)
{
}

FastInternal::FastWindow::~FastWindow()
{
}

void FastInternal::FastWindow::Draw()
{
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
uint FastInternal::FastHash::F(uint4 x, uint4 y, uint4 z) {
	return x & y | ~x&z;
}

uint FastInternal::FastHash::G(uint4 x, uint4 y, uint4 z) {
	return x & z | y & ~z;
}

uint FastInternal::FastHash::H(uint4 x, uint4 y, uint4 z) {
	return x ^ y^z;
}

uint FastInternal::FastHash::I(uint4 x, uint4 y, uint4 z) {
	return y ^ (x | ~z);
}

// rotate_left rotates x left n bits.
uint FastInternal::FastHash::rotate_left(uint4 x, int n) {
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

void FastInternal::FastDrawShape::AddPoint(FastVec2 point_pos)
{
	if (!finished)
	{
		points.push_back(point_pos);
	}
}

void FastInternal::FastDrawShape::Finish()
{
	if (points.size() >= 3)
	{
		finished = true;

		// Calc vertext, indices and color
		if (points.size() >= 3 && finished)
		{
			num_vertices = points.size();
			num_indices = 3 * (points.size() - 2);

			vertices = new float[num_vertices * 2];
			indices = new uint[num_indices];
			color = new float[num_vertices * 4];

			// Triangulize
			for (int i = 0; i < points.size(); i++)
			{
				vertices[i * 2] = points[i].x;
				vertices[(i * 2) + 1] = points[i].y;

				// Color for vertices
				color[(i * 4) + 0] = _color.x;
				color[(i * 4) + 1] = _color.y;
				color[(i * 4) + 2] = _color.w;
				color[(i * 4) + 3] = _color.z;

				if (i > 1)
				{
					// Indices for triangle
					indices[(i - 2) * 3] = 0;
					indices[((i - 2) * 3) + 1] = i - 1;
					indices[((i - 2) * 3) + 2] = i;
				}
			}
		}
		// -----------------------------------
	}
}

void FastInternal::FastDrawShape::Clear()
{
	finished = false;

	indices.clear();
	vertices.clear();

	points.clear();
}
