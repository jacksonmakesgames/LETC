#pragma once
#include <graphics/textures/Animator2D.h>
#include <physics/PhysicsBody2D.h>
#include <gameobjects/Transform2D.h>

namespace letc {
	class GameObject {
	protected:
	public:
		Transform2D* transform = nullptr;
		const char* name;

		//glm::vec3& position		 = glm::vec3(0.0f);
		//glm::vec2& size			 = glm::vec2(0.0f);
		//glm::vec3 m_parentOffset = glm::vec3(0.0f);
	private:
		bool enabled_ = true;

		std::string m_tag = "";
		//std::vector<GameObject*> m_children;


		//glm::mat4 m_rotationMatrix		= glm::mat4(1.0f);
		//glm::mat4 m_translationMatrix	= glm::mat4(1.0f);



		//Graphics
		graphics::Renderable2D* m_renderable = nullptr;
		graphics::Animator2D* m_animator = nullptr;

		//TODO: add transform struct
		//glm::vec3 m_position = glm::vec3(0.0f);
		//float m_angle = 0.0f;
		//glm::vec2 m_size = glm::vec2(1.0f);

		// Physics
		physics::PhysicsBody2D* m_physicsBody2D;

	public:
		GameObject(const char* name, glm::vec3 position, glm::vec2 size);
		GameObject(glm::vec2 position, glm::vec2 size);
		GameObject(glm::vec3 position, glm::vec2 size);
		GameObject(glm::vec3 position, glm::vec2 size, graphics::Renderable2D* renderable);
		GameObject(glm::vec2 position, glm::vec2 size, graphics::Renderable2D* renderable);
		GameObject(glm::vec3 position, graphics::Renderable2D* renderable);
		GameObject(glm::vec2 position, graphics::Renderable2D* renderable);
		GameObject(const char* name, glm::vec2 position, glm::vec2 size, graphics::Renderable2D* renderable);
		GameObject();

		inline void setTag(std::string tag) { m_tag = tag; }
		inline std::string getTag() { return m_tag; }

		void addComponent(graphics::Renderable2D* renderable);
		void addAnimator();
		void addComponent(physics::PhysicsBody2D* physicsBody2D);

		/*void addChild(GameObject* object);
		void removeChild(GameObject* object);*/

		inline graphics::Animator2D* getAnimator() { return m_animator; }
		inline bool isEnabled() { return enabled_; }
		void disable();
		void enable();



		bool hasFixture(b2Fixture* fixture) {
			if (m_physicsBody2D == nullptr) return false;
			for (b2Fixture* f = m_physicsBody2D->getBody()->GetFixtureList(); f; f = f->GetNext()) {
				if (f == fixture) {
					return true;
				}
			}
			return false;
		}


		virtual void submit(graphics::Renderer2D* renderer) const;

		virtual void update();
		virtual void update(glm::vec2 positionOffset);

		inline const graphics::Renderable2D* getRenderable()const { return m_renderable; }

		inline physics::PhysicsBody2D* getPhysicsBody2D() {
			return m_physicsBody2D;
		}

		virtual void onCollisionEnter(b2Contact* contact) {};
		virtual void onSensorEnter(b2Contact* contact) {};

		virtual void onCollisionExit(b2Contact* contact) {};
		virtual void onSensorExit(b2Contact* contact) {};

		~GameObject();

	private:


	};
	class Physics2DContactListener : public b2ContactListener {
		void BeginContact(b2Contact* contact);
		void EndContact(b2Contact* contact);
	};


}