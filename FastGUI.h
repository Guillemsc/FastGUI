#ifndef FASTGUI
#define FASTGUI

#include <math.h> 
#include <string>
#include <vector>
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
class FastVector2
{
public:
	FastVector2(float x, float y);

	void operator += (const FastVector2& vec);
	void operator -= (const FastVector2& vec);
	void operator *= (const FastVector2& vec);
	void operator /= (const FastVector2& vec);

	float Distance(const FastVector2& vec);

public:
	float x = 0.0f;
	float y = 0.0f;
};

class FastVector3
{
public:
	FastVector3(float x, float y, float z);

	void operator += (const FastVector3& vec);
	void operator -= (const FastVector3& vec);
	void operator *= (const FastVector3& vec);
	void operator /= (const FastVector3& vec);

	float Distance(const FastVector3& vec);

public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

class FastVector4
{
public:
	FastVector4(float x, float y, float w, float z);

	void operator += (const FastVector4& vec);
	void operator -= (const FastVector4& vec);
	void operator *= (const FastVector4& vec);
	void operator /= (const FastVector4& vec);

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

	FastVector2 Center();

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
	void Init();
	void Quit();

	const char* GetVersion();

	void PushID(const char* id);
	void PopID();
}

namespace FastInternal
{
	// Forward declarations
	class FastIO;
	class FastStyle;
	class FastFonts;
	class FastDraw;
	class FastHash;
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

		FastElement* GetElement(std::string hash);
		void PushElement(FastElement* el);

		FastWindow* GetCurrWindow();

	private:


	public:
		FastIO*    io = nullptr;
		FastStyle* style = nullptr;
		FastFonts* fonts = nullptr;
		FastDraw*  draw = nullptr;
		FastHash*  hash = nullptr;

	private:
		std::map<std::string, FastElement*> elements;
	};

	bool Inited();

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

	class FastDraw
	{
	public:
		 FastDraw();
		~FastDraw();
	};

	class FastHash
	{
	public: 
		FastHash();
		~FastHash();
	};

	class FastElement
	{
	public:
		FastElement();
		~FastElement();
	};

	class FastWindow
	{
	public:
		FastWindow();
		~FastWindow();
	};
}

namespace FastDraw
{

}

#endif // !FASTUI
