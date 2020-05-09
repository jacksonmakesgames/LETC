#pragma once
#ifdef dWATTY_EMSCRIPTEN
#include <emscripten.h>
#else
#include <soloud.h>
#include <soloud_wav.h>
#endif // WATTY_EMSCRIPTEN
#include <iostream>
#include <string>
#include "../utils/string_utils.h"

namespace letc {namespace audio {
	class AudioClip {
	private:
		std::string m_name;
		std::string m_filepath;
#ifdef dWATTY_EMSCRIPTEN
		 // TODO: error checking
#else
		SoLoud::Soloud* m_soloudPtr;
		SoLoud::Wav wavFile; // TODO: Other file types? Seems like ogg already works for some reason....
#endif // WATTY_EMSCRIPTEN
		
		int m_handle = 0;

		float m_gain;
		bool m_playing = false;
		bool m_looping = false;
		int m_SeekPosition;


	public:
#ifdef dWATTY_EMSCRIPTEN
		AudioClip(const std::string& name, const std::string& filepath);
#else
		AudioClip(const std::string& name, const std::string& filepath, SoLoud::Soloud* soloudPtr);
#endif // WATTY_EMSCIPTEN

		~AudioClip();

		void play(bool loop);
		void pause();
		void resume();
		void stop();

		void setGain(float gain);

		inline const std::string& getName() { return m_name; }
		inline const float getGain() { return m_gain; }
		inline const std::string& getFilePath() { return m_filepath; }
		inline const bool isPlaying() { return m_playing; }
	private:
		void init();
	};

}}
