#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"

#include "renderer2d.h"

#include "texture.h"

#include "../math/math.h"
#include "shader.h"

namespace letc {namespace graphics {
	struct VertexData
	{
		math::Vector3 vertex;
		math::Vector2 uv;
		float tid;
		unsigned int color;
	};

	struct FrameInfo {
		float currentFrame;
		float totalFrames;

	};

	class Renderable2D{
	public:
		math::Vector3& position;
		math::Vector2& size;
	protected:
		math::Vector2 m_size;
		math::Vector3 m_position;
		float m_rotation = 0;
		unsigned int m_color;
		std::vector<math::Vector2> m_UVs;
		Texture* m_texture; 
		math::Matrix4 m_transformationMatrix;

		FrameInfo m_frameInfo;

	private:
		std::vector<Renderable2D*> m_childrenRenderables = std::vector<Renderable2D*>();

	protected:
		Renderable2D() : position(m_position), size(m_size) {
			setUVDefaults();
			m_texture = nullptr;
		}
			


	public:
		Renderable2D(math::Vector3 position, math::Vector2 size, unsigned int color)
		: m_position(position), m_size(size), m_color(color), position(m_position), size(m_size) {
			setUVDefaults();
			m_texture = nullptr;
			m_size = size;
			m_position = position;
		}

		void setTransformationMatrix(math::Matrix4 matrix) {
			m_transformationMatrix = matrix;
		}

		virtual ~Renderable2D() {
		}

		virtual void submit(Renderer2D* renderer)const {
			// todo we should cache EmptyMat
			bool emptyMat = m_transformationMatrix.isEmpty();
			if(!emptyMat)
				renderer->push(m_transformationMatrix);
			renderer->submit(this);
			if(!emptyMat)
				renderer->pop();

		}

		void setColor(unsigned int color) { m_color = color; }
		void setColor(math::Vector4 color) {
			int	r = color.x * 255.0f;
			int	g = color.y * 255.0f;
			int	b = color.z * 255.0f;
			int	a = color.w * 255.0f;
			m_color = a << 24 | b << 16 | g << 8 | r;
		}

		virtual const std::vector<Renderable2D*>& getChildren() const {
			return m_childrenRenderables;
		}


		inline const math::Vector2& getSize()const{ return m_size; }
		inline const math::Vector3& getPosition()const{ return m_position; }
		inline const unsigned int getColor()const{ return m_color; }
		inline const std::vector<math::Vector2>& getUVs()const{ return m_UVs; }

		inline const GLuint getTID() const { return m_texture == nullptr ? 0 : m_texture->getID(); }
		inline const Texture* getTexture() const { return m_texture == nullptr ? nullptr : m_texture; }
		inline const FrameInfo getFrameInfo() const { return m_frameInfo; }

		inline void setFrameInfo(FrameInfo frameInfo) { m_frameInfo = frameInfo; }

	private:
		void setUVDefaults() {
			m_UVs.push_back(math::Vector2(0, 0));
			m_UVs.push_back(math::Vector2(0, 1));
			m_UVs.push_back(math::Vector2(1, 1));
			m_UVs.push_back(math::Vector2(1, 0));

			m_frameInfo.currentFrame = 0.0f;
			m_frameInfo.totalFrames = 1.0f;
		}
	};
}}