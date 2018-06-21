#ifndef FASTGUI
#define FASTGUI

#include <math.h> 
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <assert.h>

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

#define FAST_ASSERT(_EXPR, _MSG) assert(_EXPR && _MSG)

// TYPEDEFS
typedef unsigned int uint;
typedef unsigned char uchar;

// CLASSES
class FastVec2
{
public:
	FastVec2(float x, float y);

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
	FastVec3(float x, float y, float z);

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
	FastVec4(float x, float y, float w, float z);

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

class FastRect
{
public:
	FastRect(float x, float y, float w, float h);

	float xw();
	float yh();

	FastVec2 Center();

	bool Overlaps(FastRect rec);
	bool Contains(FastRect rec);

public:
	float x = 0.0f;
	float y = 0.0f;
	float w = 0.0f;
	float h = 0.0f;
};

namespace Fast
{
	const char* GetVersion();

	void PushID(const char* id);
	void PopID();
}

namespace FastInternal
{
	void Init();
	void Quit();
	void NewFrame();
	void EndFrame();

	// Forward declarations
	class FastCreation;
	class FastIO;
	class FastStyle;
	class FastFonts;
	class FastDraw;
	class FastHash;

	enum  FastElementType;
	class FastElement;
	class FastWindow;

	// Main module
	class FastMain
	{
	public:
		FastMain();
		~FastMain();

		void Start();
		void CleanUp();

		FastWindow* GetCurrWindow();

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

	class FastIO
	{
	public:
		FastIO();
		~FastIO();
	};

	class FastStyle
	{
	public:
		FastStyle();
		~FastStyle();
	};

	class FastFonts
	{
	public:
		FastFonts();
		~FastFonts();
	};

	//-----------------------------------------------------------------------------
	// FAST DRAW
	//-----------------------------------------------------------------------------

	class FastDraw
	{
	public:
		 FastDraw();
		~FastDraw();

		void Quad(FastVec2 pos, FastVec2 size, FastVec4 colour);
	};

	class FastDrawShape
	{
		FastDrawShape();

		void AddPoint(FastVec2 point_pos);
		void Finish();
		void Clear();

	private:
		std::vector<int> indices;
		std::vector<float> vertices;

		bool finished = false;
		std::vector<FastVec2> points;
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

		void Draw();
	};
}

namespace FastDraw
{

}

#endif // !FASTUI
