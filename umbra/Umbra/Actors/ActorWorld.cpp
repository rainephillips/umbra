#include "ActorWorld.h"

#include "ActorTransform.h"

void ActorWorld::Spawn(Actor* actor)
{
	// Verify that the spawning actor isn't already spawned
	if (std::ranges::find(m_actors, actor) != m_actors.end())
	{
		return;
	}

	m_listChanges.emplace_back([this](Actor* spawned)
		{
			spawned->BeginPlay();
			m_actors.emplace_back(spawned);
		}, actor);
}

void ActorWorld::Destroy(Actor* actor)
{
	// Verify that the spawning actor is already spawned
	if (std::ranges::find(m_actors, actor) == m_actors.end())
	{
		return;
	}

	m_listChanges.emplace_back([this](Actor* spawned)
		{
			spawned->EndPlay();
			m_actors.erase(std::ranges::find(m_actors, spawned));
			delete spawned;
		}, actor);
}

ActorWorld::ActorWorld() = default;

ActorWorld::~ActorWorld()
{
	// Apply any remaining changes (in case an actor was
	// in the process of being spawned)
	for (auto& [fnc, actor] : m_listChanges)
	{
		fnc(actor);
	}

	// Delete every actor in the world
	for (Actor* actor : m_actors)
	{
		delete actor;
	}

	m_actors.clear();
	m_listChanges.clear();
}

void ActorWorld::Tick(float dt)
{
	// Apply all pending changes to the actor list
	for (auto& [fnc, actor] : m_listChanges)
	{
		fnc(actor);
	}

	m_listChanges.clear();

	for (Actor* actor : m_actors)
	{
		actor->Tick(dt);
		actor->Transform()->Update();
	}
}

void ActorWorld::Render() const
{
	for (Actor* actor : m_actors)
	{
		actor->Render();
	}
}
