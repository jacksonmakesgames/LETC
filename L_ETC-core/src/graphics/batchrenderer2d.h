#pragma once

#include <cstddef>

#include "buffers/indexbuffer.h"
#include "renderer2d.h"
#include "renderable2d.h"

#define RENDERER_MAX_SPRITES		60000
#define RENDERER_VERTEX_SIZE		sizeof(VertexData)
#define RENDERER_SPRITE_SIZE		RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE		RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE		RENDERER_MAX_SPRITES * 6
#define RENDERER_TEXTURES_PER_DRAW	32 /*MAX: 32*/

#define SHADER_VERTEX_INDEX		0
#define SHADER_UV_INDEX		1
#define SHADER_TID_INDEX		2
#define SHADER_COLOR_INDEX		3

namespace letc {namespace graphics {
	class BatchRenderer2D : public Renderer2D {
	private:
		GLuint m_vertexArray;
		GLuint m_vertexBuffer;
		IndexBuffer* m_indexBuffer;
		GLsizei m_indexCount;
		VertexData* m_buffer;

		std::vector<float> m_glTIDsThisFlush;

	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		void begin() override;
		void submit(const Renderable2D* renderable) override;
		void end() override;
		void flush() override;
		void drawString(const std::string& text, const math::Vector3& position, const Font& font, unsigned int color) override;


	private:
		void init();
	};

}}