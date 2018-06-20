#ifndef FASTGUI
#define FASTGUI

#define FASTGUI_VERSION 0.01

namespace Fast
{
	void Init();
}

namespace FastInternal
{
	class FastMain
	{
	public:
		FastMain();
		~FastMain();
	};
}

static FastInternal::FastMain* fast_main = nullptr;

namespace FastDraw
{

}

#endif // !FASTUI
