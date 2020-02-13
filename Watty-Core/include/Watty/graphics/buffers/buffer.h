#pragma once
#ifdef WATTY_OPENGL
#include <ext/glad/include/glad/glad.h>
#endif
namespace letc {namespace graphics {
	
	class Buffer {
	private:
		unsigned int m_bufferID;
		unsigned int m_componentCount;
	public:
		Buffer(float* data, int count, unsigned int componentCount);
		~Buffer();
		void bind() const;
		void unbind() const;

		inline unsigned int getComponentCount() const { return m_componentCount; };
	};
	
}}