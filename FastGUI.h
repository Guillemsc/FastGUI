#ifndef FASTGUI
#define FASTGUI

#include <math.h> 
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>
#include <functional>

#define FASTGUI_VERSION "0.01"

// ---------------------------------------------------------------------------------------------------------
// STB Truetype --------------------------------------------------------------------------------------------

#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "stb_truetype.h"

// ---------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------
// Defines -------------------------------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------
// Typedefs ------------------------------------------------------------------------------------------------

typedef unsigned int Fuint;
typedef unsigned char Fuchar;

// ---------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------
// Custom general use classes ------------------------------------------------------------------------------

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
	FastColour(int hexadecimal_val);

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

	void operator = (const FastRect& rect);

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
	FastVector() { };
	FastVector(const FastVector& element) { Substitute(element); };
	~FastVector() { Clear(); };

	TYPE& operator[] (Fuint index) { FAST_ASSERT(index < data_capacity, "Index out of boundaries"); return data_array[index]; };
	void operator = (const FastVector & element) { Substitute(element); };
	void operator += (const FastVector& element) { Concatenate(element); };

	inline void PushBack(TYPE element)
	{
		if (data_capacity < data_used + 1)
			Resize(data_capacity + chunk_size);

		data_array[data_used++] = element;
	};

	inline void RemoveAt(int index)
	{
		FAST_ASSERT(index < data_capacity, "Index out of boundaries");

		for (int i = index; i < data_used - 1; ++i)
			data_array[i] = data_array[i + 1];

		if (data_used > 0)
			--data_used;

		if (data_capacity > data_used + chunk_size)
			Resize(data_capacity - chunk_size);
	};

	inline void Clear() { FAST_DEL_ARRAY(data_array); data_capacity = 0; data_used = 0; };
	inline int Size() { return data_used; };
	inline TYPE* Data() { return data_array; };

private:
	void Resize(Fuint size)
	{
		if (size > 0 && size > data_used)
		{
			if (data_capacity > 0)
			{
				TYPE* new_data = nullptr;
				new_data = new TYPE[size];

				for (int i = 0; i < data_used; ++i)
					new_data[i] = data_array[i];

				data_capacity = size;

				FAST_DEL_ARRAY(data_array);

				data_array = new_data;
			}
			else
			{
				data_array = new TYPE[size];
				data_capacity = size;
			}
		}
	};

	void Substitute(const FastVector& element)
	{
		Clear();
		Resize(element.data_used + chunk_size);

		for (int i = 0; i < element.data_used; ++i)
			data_array[i] = element.data_array[i];

		data_used = element.data_used;
	};

	void Concatenate(const FastVector& element)
	{
		int new_size = data_used + element.data_used;

		if (new_size > data_capacity)
			Resize(new_size);

		for (int i = 0; i < element.data_used; ++i)
			data_array[i] = element.data_array[i];

		data_used = new_size;
	};

private:
	TYPE *    data_array = nullptr;
	Fuint     data_capacity = 0;

	Fuint     data_used = 0;

	const int chunk_size = 1;
};

// ---------------------------------------------------------------------------------------------------------

namespace FastInternal
{
	// -----------------------------------------------------------------------------------------------------
	// Forward declarations --------------------------------------------------------------------------------

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

	class FastElements;

	// -----------------------------------------------------------------------------------------------------

	// -----------------------------------------------------------------------------------------------------
	// Internal exposed functions --------------------------------------------------------------------------

	// Implementation
	void Init();
	void Quit();
	void NewFrame(FastVec2 window_size, FastVec2 mouse_pos, float delta_time);
	void EndFrame();
	void SetLoadTexture(std::function<int(Fuchar* data, FastVec2 size)> load_texture);

	// Io
	FastVec2 GetViewport();
	void SetKeyMapping(FastInternal::FastKeyMapping fast_key, Fuint maping_index);
	void SetMouseLeftButton(bool set);
	void SetMouseRightButton(bool set);

	// Elements
	FastVector<FastWindow*> GetWindows();

	// Debug
	std::vector<FastDrawShape> GetDebugShapes();

	// -----------------------------------------------------------------------------------------------------

	// -----------------------------------------------------------------------------------------------------
	// Internal classes ------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// Main Module
	//-----------------------------------------------------------------------------
	class FastModule
	{
	public:
		virtual void Start() = 0;
		virtual void CleanUp() = 0;
		virtual void StartFrame() {};
		virtual void EndFrame() {};
	};

	class FastMain
	{
	public:
		FastMain();
		~FastMain();

		void Start();
		void StartFrame();
		void EndFrame();
		void CleanUp();

		std::function<int(Fuchar* data, FastVec2 size)> load_texture;

	private:
		void AddModule(FastModule* mod);

	public:
		FastIO*        io = nullptr;
		FastStyle*     style = nullptr;
		FastFonts*     fonts = nullptr;
		FastDraw*      draw = nullptr;
		FastElements*  elements = nullptr;

	private:
		std::vector<FastModule*> modules;
	};

	bool CheckInited();

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// Input Output
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

	class FastIO : public FastModule
	{
	public:
		FastIO();
		~FastIO();

		void Start();
		void StartFrame();
		void CleanUp();

		void SetViewportSize(const FastVec2& set);
		FastVec2 GetViewportSize() const;

		bool GetKeyDown(const FastKeyMapping& key) const;

		void SetMousePos(const FastVec2& set);
		FastVec2 GetMousePos();

		void SetLeftMouseDown(bool set);
		bool GetLeftMouseDown();
		void SetRightMouseDown(bool set);
		bool GetRightMouseDown();

		FastVec2 GetMouseMovement();

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

		FastVec2			 mouse_pos;
		FastVec2             last_frame_mouse_pos;

		bool				 left_mouse_down = false;
		bool				 right_mouse_down = false;
		FastVec2			 mouse_movement;

		float			     time_since_start_sec = 0.0f;
		Fuint				 frames_since_start = 0;
		float				 delta_time = 0.0f;		

		int					 frame_counter = 0;
		float				 frame_counter_ms = 0.0f;
		int					 last_second_frames = 60;
	};
	
	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// Style
	//-----------------------------------------------------------------------------

	struct FastStylePhyisical
	{
		float win_title_bar_height;
		float win_x_padding;
		float win_y_padding;
		float widget_height;
		float widget_x_padding;
		float widget_y_padding;
		float widgets_y_separation;
	};

	struct FastStyleColours
	{
		FastColour win_bg;
		FastColour win_title_bar;
		FastColour text;
		FastColour widget_bg;
	};

	struct FastStyleElements
	{
		float			   alpha = 1.0f;
		FastStylePhyisical physical;
		FastStyleColours   colours;
	};

	class FastStyle : public FastModule
	{
	public:
		FastStyle();
		~FastStyle();

		void Start();
		void CleanUp();

		void SetDefaultStyle();

	public:
		FastStyleElements def;
	};

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// Fonts
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

	class FastFonts : public FastModule
	{
	public:
		FastFonts();
		~FastFonts();

		void Start();
		void CleanUp();

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
	// Draw
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
		std::vector<Fuint> GetIndices();
		Fuint GetIndicesCount();
		float* GetVerticesPtr();
		std::vector<float> GetVertices();
		float* GetColoursPtr();
		std::vector<float> GetColours();
		float* GetUvsPtr();
		std::vector<float> GetUvs();
		float* GetVerticesColourUvsPtr();
		std::vector<float> GetVerticesColoursUvs();

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
		std::vector<Fuint>     indices;
		std::vector<float>     vertices;
		std::vector<float>     colours;
		std::vector<float>     uvs;
		std::vector<float>     vertices_colour_uvs;

		Fuint				  curr_indices_count = 0;

		Fuint                 texture_id = 0;

		bool				  finished = false;
		std::vector<FastVec2> points;

		bool				  uses_clipping_rect = false;
		FastRect			  clipping_rect;

		FastVec4			  quad_size;
	};

	enum FastDrawTextAlign
	{
		FAST_DRAW_TEXT_ALIGN_LEFT,
		FAST_DRAW_TEXT_ALIGN_CENTER,
		FAST_DRAW_TEXT_ALIGN_RIGHT,
	};

	struct FastDrawTextLineInfo
	{
		float x_size = 0;
		Fuint max_word = 0;
	};

	class FastDraw : public FastModule
	{
	public:
		 FastDraw();
		~FastDraw();

		void Start();
		void CleanUp();

		void DrawDebug();
		std::vector<FastDrawShape>& GetDebugShapes();

		// Shape management
		void StartShape();
		void ContinueShape(const FastDrawShape& shape);
		FastDrawShape FinishShape();

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
		void Text(FastVec2 pos, FastVec2 size, FastFont* font, std::string text, FastDrawTextAlign align, bool overflow, FastColour colour);

		void BezierQuad(FastVec2 pos, FastVec2 size, FastVec2 p1, FastVec2 p2); // Not working

	private:
		std::vector<FastDrawShape> debug_shapes;

		bool	      drawing_shape = false;
		FastDrawShape curr_shape;

		bool	      clipping_enabled = false;
		FastRect      curr_clipping_rect;
	};

	// ----------------------------------------------------------------------------

	//-----------------------------------------------------------------------------
	// Fast Elements
	//-----------------------------------------------------------------------------

	enum FastElementType
	{
		FAST_BUTTON,
		FAST_TEXT,
	};

	class FastInteractableRect
	{
	public:
		FastInteractableRect();
		FastInteractableRect(const FastRect& rect);

		FastRect rect;
		bool hovered = false;
	};

	class FastElement
	{
		friend FastElements;

	public:
		FastElement(const FastElementType& type, const FastStyleElements& default_style, FastWindow* window);
		~FastElement();

		void BaseUpdate();

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void CleanUp() = 0;

		FastVector<FastDrawShape>& GetShapes();

		virtual FastVec2 RecalucalteRect(const FastVec2& starting_pos) = 0;

		void SetStyle(const FastStyleElements& style);
		
	protected:
		void Redraw();
		virtual void DoRedraw() = 0;
		void CheckMouseInput();

	protected:
		FastElementType   type;
		FastStyleElements style;
		FastWindow* window = nullptr;

		FastVector<FastDrawShape> draw_shapes;
		bool     needs_redraw = false;

		FastRect rect;
		FastRect last_rect;

		bool     hovered = false;
		FastVector<FastInteractableRect> interactable_rects;
	};

	class FastElementText : public FastElement
	{
		friend FastWindow;

	public:
		FastElementText(const FastStyleElements& default_style, FastWindow* window);
		~FastElementText();

		void Start();
		void Update();
		void CleanUp();

		void SetText(std::string txt);

	private:
		FastVec2 RecalucalteRect(const FastVec2& starting_pos);
		void DoRedraw();

	private:
		std::string text;
	};

	class FastWindow 
	{
		friend FastElementText;
		friend FastElements;
	public:
		FastWindow(const FastStyleElements& default_style);
		~FastWindow();

		void Start();
		void Update();
		void CleanUp();
		
		FastElement* AddElement(const FastElementType& type);

		FastVector<FastDrawShape>& GetShapes();
		FastVector<FastElement*>& GetElements();

		void SetStyle(const FastStyleElements& style);
		void SetTitle(std::string title);
		void SetUseTitle(bool set);
		void SetPos(const FastVec2& pos);
		void AddPos(const FastVec2 add);
		void SetAnchor(const FastVec2& anchor);
		void SetSize(const FastVec2& size);

	private:
		FastRect GetWindowDrawingRect();

		void Redraw();
		void DoRedraw();

		void RecalucalteRect();
		void RecalculateElementsRect();
		void CheckMouseInput();

	private:
		FastStyleElements style;

		FastVector<FastDrawShape> draw_shapes;
		bool     needs_redraw = false;

		FastVector<FastElement*> elements;

		FastRect rect;
		FastRect last_rect;

		FastVec2 local_pos;
		FastVec2 anchor;

		bool     dragging = false;

		bool     interactable = true;
		bool	 visible = true;
		bool     draggable = false;

		std::string title_text;
		bool	 uses_title_text = true;

		bool hovered = false;
		FastVector<FastInteractableRect> interactable_rects;
	};

	class FastElements : public FastModule
	{
		friend FastWindow;
		friend FastElement;

	public:
		FastElements();
		virtual ~FastElements();

		void Start();
		void CleanUp();
		void StartFrame();

		FastVector<FastWindow*>& GetWindows();

		FastWindow* CreateWin();

	private:
		void HandleElementsInput();

	private:
		FastVector<FastWindow*> windows;

		// Windows input control
		FastWindow* hovered_window = nullptr;
		FastWindow* last_hovered_window = nullptr;

		FastElement* hovered_element = nullptr;
		FastElement* last_hovered_element = nullptr;

		FastWindow* focused_window = nullptr;
	};


	// -----------------------------------------------------------------------------------------------------
}

namespace Fast
{
	// -----------------------------------------------------------------------------------------------------
	// User exposed functions ------------------------------------------------------------------------------

	const char* GetVersion();
	Fuint FPS();

	void LoadFont(const char* filepath);

	FastInternal::FastWindow* Window();

	// -----------------------------------------------------------------------------------------------------
}


#endif // !FASTUI
