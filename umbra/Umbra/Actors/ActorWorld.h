#pragma once

#include <functional>
#include <vector>

#include "Actor.h"

using std::function;
using std::pair;
using std::vector;

class Actor;

class ActorWorld
{
	friend class Level;

public:
	void Spawn(Actor* actor);
	void Destroy(Actor* actor);

private:
	vector<Actor*> m_actors;
	vector<pair<function<void(Actor*)>, Actor*>> m_listChanges;

private:
	ActorWorld();
	~ActorWorld();

private:
	void Tick(float dt);
	void Render() const;
};

