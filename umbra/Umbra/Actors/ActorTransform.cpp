#include "ActorTransform.h"

#include <Raylib/raymath.h>

ActorTransform::ActorTransform()
	: ActorTransform{ Vector2{0.f, 0.f}, 0.f, Vector2{1.f, 1.f} }
{
}

ActorTransform::ActorTransform(Vector2 location, float rotation)
	: ActorTransform{ location, rotation, Vector2{1.f, 1.f} }
{
}

ActorTransform::ActorTransform(Vector2 location, Vector2 scale)
	: ActorTransform{ location, 0.f, scale }
{
}

ActorTransform::ActorTransform(Vector2 location, float rotation, Vector2 scale)
	: location{ location }, rotation{ rotation }, scale{ scale }
{
	Update();
}

Vector2 ActorTransform::Forward() const
{
	return Vector2Transform({ 0.f, -1.f }, m_transform);
}

Vector2 ActorTransform::Right() const
{
	return Vector2Transform({ 1.f, 0.f }, m_transform);
}

void ActorTransform::Update()
{
	m_transform = 
		MatrixTranslate(location.x, location.y, 0.f) *
		MatrixRotateZ(rotation * DEG2RAD) *
		MatrixScale(scale.x, scale.y, 1.f);
}
