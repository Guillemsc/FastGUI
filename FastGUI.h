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
	FastRect(const FastVec2& pos, const FastVec2 size);

	inline float xw();
	inline float yh();

	FastVec2 Pos();
	FastVec2 Size();
	FastVec2 Center();

	bool Overlaps(FastRect rec);
	bool Contains(FastRect rec);
	bool Contains(FastVec2 point);
	void Scissor(FastRect rec);

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

template<class TYPE>
class FastVector
{
public:
	FastVector();
	FastVector(const FastVector& element);
	~FastVector();

	TYPE operator[] (Fuint index);
	void operator = (const FastVector& element);
	void operator += (const FastVector& element);

	void PushBack(const TYPE& element);
	void RemoveAt(int index);
	void Clear();
	int Size();
	TYPE* Data();

private:
	void Resize(Fuint size);
	void Substitute(const FastVector& element);
	void Concatenate(const FastVector& element);

private:
	TYPE*     data_array = nullptr;
	Fuint     data_capacity = 0;

	Fuint     data_used = 0;

	const int chunk_size = 2;

};

namespace Fast
{
	const char* GetVersion();

	void LoadFont(const char* filepath);

	void PushID(const char* id);
	void PopID();

	void Window(const char* name, FastVec2 pos);
}

namespace FastInternal
{
	// Forward declarations
	class FastMain;

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

	// General implementation functions
	void Init();
	void Quit();
	void NewFrame(FastVec2 window_size, FastVec2 mouse_pos, float delta_time);
	void EndFrame();
	void SetLoadTexture(std::function<int(Fuchar* data, FastVec2 size)> load_texture);

	// Shapes
	FastVector<FastDrawShape> GetShapes();
	void ClearShapes();

	// IO
	FastVec2 GetViewport();
	void SetKeyMapping(FastInternal::FastKeyMapping fast_key, Fuint maping_index);

	// Main module
	class FastMain
	{
	public:
		FastMain();
		~FastMain();

		void Start();
		void CleanUp();

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
		FAST_KEY_UP_ARROW,
		FAST_KEY_DOWN_ARROW,
		FAST_KEY_PAGE_UP,
		FAST_KEY_PAGE_DOWN,
		FAST_KEY_DELETE,
		FAST_KEY_BACKSPACE,
		FAST_KEY_ENTER,
		FAST_KEY_ESCAPE,
		FAST_KEY_C,
		FAST_KEY_V,
		FAST_KEY_X,
		FAST_KEY_Z,
		FAST_KEY_Y,
		FAST_KEY_COUNT
	};

	enum FastMouseState
	{
		FAST_MOUSE_IDLE,
		FAST_MOUSE_DOWN,
	};

	enum FastMouseCenterState
	{
		FAST_MOUSE_CENTER_STATE_UP,
		FAST_MOUSE_CENTER_STATE_DOWN,
		FAST_MOUSE_CENTER_STATE_IDLE,
	};

	class FastIO
	{
	public:
		FastIO();
		~FastIO();

		void SetViewportSize(const FastVec2& set);
		FastVec2 GetViewportSize() const;

		bool GetKeyDown(const FastKeyMapping& key) const;

		void SetMousePos(const FastVec2& set);

		void AddKeyMaping(FastKeyMapping key, Fuint maped_key);

		void AddNewFrame(float delta_time);
		Fuint GetFramesSinceStart() const;
		float GetTimeSinceStartSec() const;
		float GetDeltaTime() const;
		float GetAvgFps() const;
		Fuint GetFps() const;

	private:
		FastVec2             viewport_size;

		Fuint				 key_maping[FastKeyMapping::FAST_KEY_COUNT];

		FastMouseState       mouse_left_button = FastMouseState::FAST_MOUSE_IDLE;
		FastMouseState       mouse_right_button = FastMouseState::FAST_MOUSE_IDLE;

		FastMouseCenterState mouse_center_button = FastMouseCenterState::FAST_MOUSE_CENTER_STATE_IDLE;

		FastVec2			 mouse_pos;

		float			     time_since_start_sec = 0.0f;
		Fuint				 frames_since_start = 0;
		float				 delta_time = 0.0f;		

		int					 frame_counter = 0;
		float				 frame_counter_ms = 0.0f;
		int					 last_second_frames = 60;
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

		void CleanUp();

		void SetFontScale(float set);
		float GetFontScale();

		FastGlyph GetGlyphByChar(Fuchar c);

	public:
		Fuchar*  texture_data = nullptr;
		Fuint    texture_id = 0;
		FastVec2 size = FastVec2(0, 0);

		std::vector<FastGlyph> glyphs;

	private:
	

	private:
		stbtt_fontinfo info;
		float		   scale = 0.0f;
	};

	class FastGlyph
	{
	public:
		FastGlyph();

		FastVec2 uvs_x0;
		FastVec2 uvs_y0;
		FastVec2 uvs_x1;
		FastVec2 uvs_y1;

		float    ratio_x_y = 0.0f;
	};

	enum FastFontRange
	{
		FAST_FONT_RANGE_LATIN,
		FAST_FONT_RANGE_KOREAN,
		FAST_FONT_RANGE_CHINESE,
		FAST_FONT_RANGE_JAPANESE,
		FAST_FONT_RANGE_CYRILLIC,
		FAST_FONT_RANGE_THAI,
	};

	class FastFonts
	{
	public:
		FastFonts();
		~FastFonts();

		void LoadFont(const char* path, int font_size, FastFontRange range = FastFontRange::FAST_FONT_RANGE_LATIN);

		FastFont* GetCurrFont() const;

	private:
		FastVec2 TexturePosToUV(FastVec2 texture_size, FastVec2 pos);

		std::vector<FastVec2> GetBaseGlyphsRanges();
		std::vector<FastVec2> GetLatinGlyphsRanges();
		std::vector<FastVec2> GetKoreanGlyphsRanges();
		std::vector<FastVec2> GetChineseGlyphsRanges();
		std::vector<FastVec2> GetJapaneseGlyphsRanges();
		std::vector<FastVec2> GetCyrillicGlyphsRanges();
		std::vector<FastVec2> GetThaiGlyphsRanges();

	private:
		FastFont* curr_font = nullptr;
	};

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// FAST DRAW
	//-----------------------------------------------------------------------------

	class FastDrawShape
	{
	public:
		FastDrawShape();

		void AddPoint(FastVec2 point_pos);
		void AddTextureId(Fuint id);
		void Finish(FastColour colour);
		void Finish(FastColour colour, FastVec4 range_uvs);
		void Clear();
		void SetClippingRect(const FastRect& rect);

		Fuint* GetIndicesPtr();
		FastVector<Fuint> GetIndices();
		Fuint GetIndicesCount();
		float* GetVerticesPtr();
		FastVector<float> GetVertices();
		float* GetColoursPtr();
		FastVector<float> GetColours();
		float* GetUvsPtr();
		FastVector<float> GetUvs();
		float* GetVerticesColourUvsPtr();
		FastVector<float> GetVerticesColoursUvs();

		bool GetUsesClippingRect() const;
		FastRect GetClippingRect() const;

		Fuint GetTextureId();

		Fuint Offset();
		Fuint VerticesOffset() const;
		Fuint VerticesSize() const;
		Fuint ColourOffset() const;
		Fuint ColoursSize() const;
		Fuint UvsOffset() const;
		Fuint UvsSize() const;

	private:
		FastVector<Fuint>     indices;
		FastVector<float>     vertices;
		FastVector<float>     colours;
		FastVector<float>     uvs;
		FastVector<float>     vertices_colour_uvs;

		Fuint				  curr_indices_count = 0;

		Fuint                 texture_id = 0;

		bool				  finished = false;
		FastVector<FastVec2>  points;

		bool				  uses_clipping_rect = false;
		FastRect			  clipping_rect;

		FastVec4			  quad_size;
	};

	class FastDraw
	{
	public:
		 FastDraw();
		~FastDraw();

		// Shape management
		void StartShape();
		void FinishShape();

		// Clipping
		void SetClipping(const FastRect& set);
		void DisableClipping();

		// Basics
		void Line(FastVec2 start, FastVec2 end, FastColour colour);
		void Quad(FastVec2 pos, FastVec2 size, FastColour colour);
		void Circle(FastVec2 pos, float radius, FastColour colour);
		void CircleQuarter(FastVec2 pos, float radius, float starting_angle, FastColour colour);
		void ImageQuad(FastVec2 pos, FastVec2 size, Fuint image_id);
		void DownTraingle(FastVec2 pos, float size, FastColour colour);
		void RightTraingle(FastVec2 pos, float size, FastColour colour);

		// Composed
		void RoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, FastColour colour);
		void TopRoundedQuad(FastVec2 pos, FastVec2 size, float round_radius, FastColour colour);

		void FontAtlas(FastVec2 pos, FastVec2 size, FastFont* font, FastColour colour);
		void Text(FastVec2 pos, float size, FastFont* font, std::string text, FastColour colour);

		void BezierQuad(FastVec2 pos, FastVec2 size, FastVec2 p1, FastVec2 p2); // Not working

		FastVector<FastDrawShape> GetShapes();
		void ClearShapes();
	private:

	private:
		FastVector<FastDrawShape> shapes;
		
		bool	      drawing_shape = false;
		FastDrawShape curr_shape;

		bool	      clipping_enabled = false;
		FastRect      curr_clipping_rect;
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

#endif // !FASTUI
