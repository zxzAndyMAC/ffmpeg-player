
#if defined(_FF_DEBUG_)
#include "vld.h"
#endif
#include "MediaState.h"

static FFMPEG::MediaState* s_ms = nullptr;

namespace FFMPEG {
	IFFMpeg* SimpleFFmpeg::createInstance()
	{
		if (s_ms == nullptr)
		{
			s_ms = new MediaState();
		}
		return s_ms;
	}

	IFFMpeg* SimpleFFmpeg::getInstance()
	{
		return s_ms;
	}

	void SimpleFFmpeg::release()
	{
		if (s_ms != nullptr)
		{
			delete s_ms;
		}
	}
}