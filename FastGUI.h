#ifndef FASTGUI
#define FASTGUI

#include <math.h> 
#include <string>
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

	bool Overlaps(const FastVector4& vec);
	bool Contains(const FastVector4& vec);

public:
	float x = 0.0f;
	float y = 0.0f;
	float w = 0.0f;
	float z = 0.0f;
};

namespace Fast
{
	void Init();
	void Quit();

	const char* GetVersion();
}

namespace FastInternal
{
	class FastMain
	{
	public:
		FastMain();
		~FastMain();
	};

	bool Inited();
}

namespace FastDraw
{

}

#endif // !FASTUI
