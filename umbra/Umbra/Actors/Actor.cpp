#include "Actor.h"

#include "ActorTransform.h"

Actor::Actor()
	: m_transform{ new ActorTransform }
{
}

Actor::Actor(Vector2 location, float rotation, Vector2 scale)
	: m_transform{ new ActorTransform{location, rotation, scale} }
{
}

Actor::~Actor()
{
	delete m_transform;
	m_transform = nullptr;
}

ActorTransform* Actor::Transform() const
{
	return m_transform;
}

void Actor::BeginPlay()
{
}

void Actor::Tick(float dt)
{
}

void Actor::Render()
{
}

void Actor::EndPlay()
{
}
