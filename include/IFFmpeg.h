#ifndef FFMPEG_SDK_H
#define FFMPEG_SDK_H

#if defined(_WIN32)
#	if defined(IFF_EXPORTS)
#		define IFF_DLL __declspec(dllexport)
#	else
#		define IFF_DLL __declspec(dllimport)
#	endif
#elif defined(__APPLE__)
#	define IFF_DLL __attribute__((visibility("default")))
#else
#	define IFF_DLL
#endif

namespace FFMPEG {

	typedef enum FFMPEG_EVENT
	{
		FF_NONE = 100,//无事件
		FF_PAUSE,//暂停
		FF_MUTE,//静音
		FF_OVER,//播放结束
		FF_QUIT,//退出
		FF_PLAY
	}FFMPEG_EVENT;

	class IFFMpeg;
	class IFF_DLL SimpleFFmpeg
	{
	public:
		static IFFMpeg* createInstance();
		static IFFMpeg* getInstance();
		static void  release();
	};

	class IFFMpeg
	{
	public:
		virtual void do_exit() = 0;
		virtual void pause() = 0;
		virtual void resume() = 0;
		virtual void mute() = 0;
		virtual void unmute() = 0;

		virtual void play(const char *filename) = 0;
		virtual void play(char* buffer, const unsigned int size) = 0;

		virtual unsigned int getWidth() = 0;
		virtual unsigned int getHeight() = 0;

		virtual int getDuration() = 0; //获取视频时长
		virtual double get_master_clock() = 0;//获取当前播放进度

		virtual FFMPEG_EVENT event_loop() = 0;
		virtual uint8_t *getData() = 0;
	};
}

#endif