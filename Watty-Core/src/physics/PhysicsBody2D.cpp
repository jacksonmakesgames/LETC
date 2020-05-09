#include <physics/PhysicsBody2D.h>
namespace letc { namespace physics {
	PhysicsBody2D::PhysicsBody2D(BodyShapes shape,glm::vec2 startingPos, float width, float height, b2BodyType type, glm::vec2 offset, float bounciness, float friction)
		:
		m_bounciness(bounciness),
		m_friction(friction),
		m_size((width* PhysicsConstants::inv_pixels_per_meter) / 2.0f, (height* PhysicsConstants::inv_pixels_per_meter) / 2.0f),
		m_worldPosition((startingPos.x + width / 2)* PhysicsConstants::inv_pixels_per_meter, (startingPos.y + height / 2)* PhysicsConstants::inv_pixels_per_meter),
		m_offset(offset),
		m_bodyType(type),
		m_bodyDef(),
		m_polygonShape(),
		m_circleShape(),
		m_fixtureDef()
	{
		// define body
		m_bodyDef.type = m_bodyType;
		m_bodyDef.position.Set(m_worldPosition.x, m_worldPosition.y);
		// create body in world
		m_body = PhysicsWorld2D::box2DWorld->CreateBody(&m_bodyDef);
		// create shape
		if (shape == BodyShapes::box) {
			m_polygonShape.SetAsBox(m_size.x, m_size.y);
			m_fixtureDef.shape = &m_polygonShape;
			// create fixture
			m_fixtureDef.density = 1.0f;
			m_fixtureDef.restitution = m_bounciness;
			m_fixtureDef.friction = m_friction;
			// attach shape to body using fixture
			m_body->CreateFixture(&m_fixtureDef);
		}
		else if (shape == BodyShapes::circle) {
			m_circleShape.m_radius = width/2.0f;
			//m_circleShape.Set(m_size.x, m_size.y);
			m_fixtureDef.shape = &m_circleShape;
			// create fixture
			m_fixtureDef.density = 1.0f;
			m_fixtureDef.restitution = m_bounciness;
			m_fixtureDef.friction = m_friction;
			// attach shape to body using fixture
			m_body->CreateFixture(&m_fixtureDef);
		}
	}

	void PhysicsBody2D::addForce(glm::vec2 direction, float amount)
	{
		b2Vec2 force(direction.x * amount, direction.y * amount);
		m_body->ApplyForceToCenter(force, true);
	}

	void PhysicsBody2D::addImpulse(glm::vec2 direction, float amount)
	{
		b2Vec2 impulse(direction.x * amount, direction.y * amount);
		m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
	}

	void PhysicsBody2D::setFixedRotation(bool fixed)
	{
		m_body->SetFixedRotation(fixed);
	}

	bool PhysicsBody2D::isFixedRotation()
	{
		return m_body->IsFixedRotation();
	}



	void PhysicsBody2D::setLinearVelocity(glm::vec2 newVelocity)
	{
		m_body->SetLinearVelocity(b2Vec2(newVelocity.x, newVelocity.y));

	}

	void PhysicsBody2D::zeroVelocity()
	{
		m_body->SetLinearVelocity(b2Vec2(0, 0));
	}

	glm::vec2 PhysicsBody2D::getBodyPosition()
	{
		b2Vec2 pos = m_body->GetPosition();
		pos *= PhysicsConstants::pixels_per_meter;
		return glm::vec2(pos.x, pos.y);
	}

	PhysicsBody2D::~PhysicsBody2D()
	{
		m_body->GetWorld()->DestroyBody(m_body);
	}



} }