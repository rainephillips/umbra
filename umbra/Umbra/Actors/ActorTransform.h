#pragma once

#include <Raylib/raylib.h>

class ActorTransform
{
	friend class ActorWorld;

public:
	Vector2 location;
	float rotation;
	Vector2 scale;

public:
	ActorTransform();
	ActorTransform(Vector2 location, float rotation);
	ActorTransform(Vector2 location, Vector2 scale);
	ActorTransform(Vector2 location, float rotation, Vector2 scale);

public:
	Vector2 Forward() const;
	Vector2 Right() const;

private:
	Matrix m_transform;

private:
	void Update();
};

