#ifndef FASTGUI
#define FASTGUI

#include <math.h> 
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>
#include <functional>

// STB TRUETYPE DEFINITION
#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "stb_truetype.h"

#define FASTGUI_VERSION "0.01"

// DEFINES
#define FAST_DEL( x )		\
    {                       \
    if( x != nullptr )      \
	    {                   \
      delete x;             \
	  x = nullptr;          \
	    }                   \
    }

#define FAST_DEL_ARRAY( x )  \
    {                       \
    if( x != nullptr )      \
	    {                   \
      delete[] x;           \
	  x = nullptr;          \
	    }                   \
                            \
    }

#define DEGTORAD   0.0174532925199432957f
#define RADTODEG   57.295779513082320876f
#define PI		   3.14159265358979323846f
#define TWO_PI	   6.28318530717958647692f
#define HALF_PI	   1.57079632679489661923f
#define QUARTER_PI 0.78539816339744830961f
#define INV_PI	   0.31830988618379067154f
#define INV_TWO_PI 0.15915494309189533576f
#define HAVE_M_PI

#define FAST_ASSERT(_EXPR, _MSG) assert(_EXPR && _MSG)

// TYPEDEFS
typedef unsigned int Fuint;
typedef unsigned char Fuchar;

// CLASSES
class FastVec2
{
public:
	FastVec2();
	FastVec2(float x, float y);

	FastVec2 operator + (const FastVec2& vec);
	FastVec2 operator - (const FastVec2& vec);
	FastVec2 operator * (const FastVec2& vec);
	FastVec2 operator * (int vec);
	FastVec2 operator * (float vec);
	FastVec2 operator / (const FastVec2& vec);
	void operator += (const FastVec2& vec);
	void operator -= (const FastVec2& vec);
	void operator *= (const FastVec2& vec);
	void operator /= (const FastVec2& vec);

	float Distance(const FastVec2& vec);

public:
	float x = 0.0f;
	float y = 0.0f;
};

class FastVec3
{
public:
	FastVec3();
	FastVec3(float x, float y, float z);

	FastVec3 operator + (const FastVec3& vec);
	FastVec3 operator - (const FastVec3& vec);
	void operator += (const FastVec3& vec);
	void operator -= (const FastVec3& vec);
	void operator *= (const FastVec3& vec);
	void operator /= (const FastVec3& vec);

	float Distance(const FastVec3& vec);

public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

class FastVec4
{
public:
	FastVec4();
	FastVec4(float x, float y, float w, float z);

	FastVec4 operator + (const FastVec4& vec);
	FastVec4 operator - (const FastVec4& vec);
	void operator += (const FastVec4& vec);
	void operator -= (const FastVec4& vec);
	void operator *= (const FastVec4& vec);
	void operator /= (const FastVec4& vec);

public:
	float x = 0.0f;
	float y = 0.0f;
	float w = 0.0f;
	float z = 0.0f;
};

class FastColour
{
public:
	FastColour();
	FastColour(float r, float g, float b);
	FastColour(const FastVec4& vec);
	FastColour(float r, float g, float b, float a);

	FastColour operator + (const FastColour& vec);
	FastColour operator - (const FastColour& vec);
	void operator += (const FastColour& vec);
	void operator -= (const FastColour& vec);
	void operator *= (const FastColour& vec);
	void operator /= (const FastColour& vec);

public:
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 0.0f;
};

class FastRect
{
public:
	FastRect();
	FastRect(float x, float y, float w, float h);
	FastRect(const FastVec4& vec);

	float xw();
	float yh();

	FastVec2 Pos();
	FastVec2 Size();
	FastVec2 Center();

	bool Overlaps(FastRect rec);
	bool Contains(FastRect rec);

public:
	float x = 0.0f;
	float y = 0.0f;
	float w = 0.0f;
	float h = 0.0f;
};

class FastBuffer
{
public:
	FastBuffer();
	FastBuffer(int size);
	FastBuffer(int width, int heigth);
	
	void SetSize(int size);
	void SetSize(int width, int heigth);
	void Reset();
	void Clear();

	void AddData(int data_ptr_pos, Fuchar * data);

	Fuchar* GetBufferData();
	bool BufferHasData() const;

	int GetWidth();
	int GetHeight();
	int GetSize();

	void FlipUpsideDown();

private:
	Fuchar * buffer = nullptr;

	int width = 0;
	int heigth = 0;
	int size = 0;
};

namespace Fast
{
	const char* GetVersion();

	void PushID(const char* id);
	void PopID();

	void Window(const char* name, FastVec2 pos);
}

namespace FastInternal
{
	// Forward declarations
	class FastCreation;
	enum  FastElementType;
	class FastElement;
	class FastWindow;

	class FastIO;
	enum  FastKeyMapping;

	class FastStyle;
	struct FastStyleColours;
	struct FastStylePhyisical;

	class FastFonts;
	class FastFont;
	class FastGlyph;

	class FastDraw;
	class FastDrawShape;

	class FastHash;

	// General functions
	void Init();
	void Quit();
	void NewFrame();
	void EndFrame();

	void LoadFont(const char* filepath);

	void SetLoadTexture(std::function<int(Fuchar* data, FastVec2 size)> load_texture);

	std::vector<FastDrawShape> GetShapes();
	void ClearShapes();

	// Main module
	class FastMain
	{
	public:
		FastMain();
		~FastMain();

		void Start();
		void CleanUp();

		FastWindow* GetCurrWindow();

		std::function<int(Fuchar* data, FastVec2 size)> load_texture;

	public:
		FastCreation * creation = nullptr;
		FastIO*        io = nullptr;
		FastStyle*     style = nullptr;
		FastFonts*     fonts = nullptr;
		FastDraw*      draw = nullptr;
		FastHash*      hash = nullptr;

	private:
	};

	bool Inited();

	class FastCreation
	{
	public:
		FastCreation();
		~FastCreation();

		FastElement* HandleElement(const char* name, FastInternal::FastElementType type, bool& created);

		FastElement* CreateElement(std::string hash, FastInternal::FastElementType type);
		FastElement* GetElement(std::string hash);

		void SetElementAlive(std::string hash);
		void RemoveDeadElements();

		void PushID(std::string id);
		void PopID();
		std::string GetCurrID() const;

	private:
		std::map<std::string, FastElement*> elements;
		std::vector<std::string> elements_alive;


		std::vector<std::string> ids;
	};

	//-----------------------------------------------------------------------------
	// FAST INPUT OUTPUT
	//-----------------------------------------------------------------------------

	enum FastKeyMapping
	{
		FAST_KEY_TAB,
		FAST_KEY_LEFT_ARROW,
		FAST_KEY_RIGHT_ARROW,
		FAST_KEY_PAGE_UP,
		FAST_KEY_PAGE_DOWN,
		FAST_KEY_PAGE_DELETE,
		FAST_KEY_PAGE_BACKSPACE,
		FAST_KEY_PAGE_ENTER,
		FAST_KEY_PAGE_ESCAPE,
		FAST_KEY_PAGE_C,
		FAST_KEY_PAGE_V,
		FAST_KEY_PAGE_X,
		FAST_KEY_PAGE_Z,
		FAST_KEY_PAGE_Y,
		FAST_KEY_COUNT
	};

	enum FastMouseState
	{
		FAST_MOUSE_IDLE,
		FAST_MOUSE_DOWN,
	};

	class FastIO
	{
	public:
		FastIO();
		~FastIO();

	private:
		FastKeyMapping key_maping[FastKeyMapping::FAST_KEY_COUNT];

		FastMouseState mouse_left_button = FAST_MOUSE_IDLE;
		FastMouseState mouse_right_button = FAST_MOUSE_IDLE;
	};
	
	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// FAST STYLE
	//-----------------------------------------------------------------------------

	struct FastStylePhyisical
	{
		FastVec2 window_padding;
		FastVec2 window_min_size;
		float    window_rounding = 0.0f;
		FastVec2 frame_padding;
		FastVec2 item_spacing;
		FastVec2 item_inner_spacing;
		float    indent_spacing = 0.0f;
		float    scrollbar_size = 0.0f;
		float    scrollbar_rounding = 0.0f;
		float    grab_min_size = 0.0f;
		float    grab_rounding = 0.0f;
	};

	struct FastStyleColours
	{
		FastColour text;
		FastColour text_disabled;
		FastColour window_bg;
		FastColour child_window_bg;
		FastColour popup_bg;
		FastColour border;
		FastColour scroll_bar_bg;
		FastColour scroll_bar_overed;
		FastColour scroll_bar_clicked;
		FastColour button;
		FastColour button_over;
		FastColour button_clicked;
		FastColour spearator;
	};

	class FastStyle
	{
	public:
		FastStyle();
		~FastStyle();

		void SetDefaultStyle();

	public:
		float			   alpha = 1.0f;
		FastStylePhyisical physical;
		FastStyleColours   colours;
	};

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// FAST FONTS
	//-----------------------------------------------------------------------------

	class FastFont
	{
	public:
		FastFont(stbtt_fontinfo font_info);
		~FastFont();

		FastGlyph GetGlyphByChar(Fuchar c);
		float GetFontScale();

	public:
		Fuchar* texture_data = nullptr;
		Fuint texture_id = 0;
		FastVec2 size = FastVec2(0, 0);

		std::vector<FastGlyph> glyphs;

	private:
	

	private:
		stbtt_fontinfo font_info;
		int		       font_size = 24;
	};

	class FastGlyph
	{
	public:
		FastGlyph();

		FastVec2 uvs_x0;
		FastVec2 uvs_y0;
		FastVec2 uvs_x1;
		FastVec2 uvs_y1;

		float    ratio_height_down = 0.0f;

		float    ratio_x_y = 0.0f;
	};

	class FastFonts
	{
	public:
		FastFonts();
		~FastFonts();

		FastFont* LoadFont(const char* path);

		FastFont* test_font = nullptr;

	private:
		FastVec2 TexturePosToUV(FastVec2 texture_size, FastVec2 pos);

	private:
		std::vector<FastFont*> fonts;
	};

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// FAST DRAW
	//-----------------------------------------------------------------------------

	class FastDraw
	{
	public:
		 FastDraw();
		~FastDraw();

		// Basics
		void Line(FastVec2 start, FastVec2 end, FastColour colour);
		void Quad(FastVec2 pos, FastVec2 size, FastColour colour);
		void Circle(FastVec2 pos, float radius, FastColour colour);
		void CircleQuarter(FastVec2 pos, float radius, float starting_angle, float roundness, FastColour colour);
		void ImageQuad(FastVec2 pos, FastVec2 size, Fuint id);

		// Composed
		void RoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, float roundness, FastColour colour);
		void TopRoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, float roundness, FastColour colour);

		void Text(FastVec2 pos, float size, FastFont* font, std::string text, float word_separation);

		void BezierQuad(FastVec2 pos, FastVec2 size, FastVec2 p1, FastVec2 p2); // Not working

		std::vector<FastDrawShape> GetShapes() const;
		void ClearShapes();
	private:

	private:
		std::vector<FastDrawShape> shapes;
	};

	class FastDrawShape
	{
	public:
		FastDrawShape();

		void AddPoint(FastVec2 point_pos);
		void AddTextureId(Fuint id);
		void Finish(FastColour colour);
		void Finish(FastColour colour, FastVec4 range_uvs);
		void Clear();

		Fuint* GetIndices();
		Fuint GetIndicesCount();
		float* GetVertices();
		float* GetColours();
		float* GetUvs();
		float* GetVerticesColourUvs();

		Fuint GetTextureId();

		Fuint Offset();
		Fuint VerticesOffset() const;
		Fuint VerticesSize() const;
		Fuint ColourOffset() const;
		Fuint ColoursSize() const;
		Fuint UvsOffset() const;
		Fuint UvsSize() const;

	private:
		std::vector<Fuint>    indices;
		std::vector<float>    vertices;
		std::vector<float>    colours;
		std::vector<float>    uvs;
		                      
		Fuint                 texture_id = 0;

		std::vector<float>    vertices_colour_uvs;

		bool				  finished = false;
		std::vector<FastVec2> points;

		FastVec4 quad_size;
	};

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// FAST HASH
	// Converted to C++ class by Frank Thilo(thilo@unix-ag.org)
	// For bzflag(http:://www.bzflag.org)
	//-----------------------------------------------------------------------------

	class FastHash
	{
	public: 
		FastHash();
		~FastHash();

		std::string GetMD5(std::string text);

	private:
		typedef unsigned int size_type; 

		std::string hexdigest() const;

		void update(const unsigned char *buf, size_type length);
		void update(const char *buf, size_type length);
		void finalize();

		void init();
		typedef unsigned char uint1;
		typedef unsigned int uint4;  
		enum { blocksize = 64 };

		void transform(const uint1 block[blocksize]);
		static void decode(uint4 output[], const uint1 input[], size_type len);
		static void encode(uint1 output[], const uint4 input[], size_type len);

		bool finalized;
		uint1 buffer[blocksize]; 
		uint4 count[2];   
		uint4 state[4];   
		uint1 digest[16]; 

		static inline uint4 F(uint4 x, uint4 y, uint4 z);
		static inline uint4 G(uint4 x, uint4 y, uint4 z);
		static inline uint4 H(uint4 x, uint4 y, uint4 z);
		static inline uint4 I(uint4 x, uint4 y, uint4 z);
		static inline uint4 rotate_left(uint4 x, int n);
		static inline void FF(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
		static inline void GG(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
		static inline void HH(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
		static inline void II(uint4 &a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

	private:
		int S11 = 7;
		int S12 = 12;
		int	S13 = 17;
		int	S14 = 22;
		int	S21 = 5;
		int	S22 = 9;
		int	S23 = 14;
		int	S24 = 20;
		int S31 = 4;
		int S32 = 11;
		int S33 = 16;
		int S34 = 23;
		int S41 = 6;
		int S42 = 10;
		int S43 = 15;
		int S44 = 21;

	};

	// ----------------------------------------------------------------------------

	enum FastElementType
	{
		FAST_WINDOW,
		FAST_BUTTON,
		FAST_TEXT,
	};

	class FastElement
	{
	public:
		FastElement(std::string hash, FastElementType type);
		~FastElement();

		void CleanUp();

		virtual void Draw() = 0;

	public:
		FastRect		rect;

	private:
		std::string     hash;
		FastElementType type;

		bool            interactable = false;
	};

	class FastWindow : public FastElement
	{
	public:
		FastWindow(std::string hash);
		~FastWindow();

		FastColour bg_colour;

		void Draw();
	};
}

namespace FastDraw
{

}

#endif // !FASTUI
