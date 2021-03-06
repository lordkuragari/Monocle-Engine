#pragma once

#include "Debug.h"
#include <list>
#include <map>
#include <string>
#include <vector>
#include "Entity.h"

namespace Monocle
{
	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		//Called when this scene becomes the currently active scene
		virtual void Begin();

		//Called when this scene is ended and a different one becomes the active scene
		virtual void End();

		//Called by the main game loop every time the scene should update game logic
		virtual void Update();

		//Called by the main game loop every time the scene should render
		void Render();

		//Add an entity to the scene
		void Add(Entity* entity);

		//Remove an entity from the scene
		void Remove(Entity* entity);

		//Remove all entities in the scene
		void RemoveAll();

		//Called by an entity when its tag has changed; the scene must reposition that entity in the tag map
		void EntityAddTag(Entity* entity, const std::string& tag);
		void EntityRemoveTag(Entity* entity, const std::string& tag);

		//Tag API
		Entity* GetFirstTag(const std::string& tag);
		std::list<Entity*>* GetAllTag(const std::string& tag);
		int GetAmountTag(const std::string& tag);

		//HACK: test function
		Entity *GetEntity(int index);

		Entity* GetEntityNearestTo(const Vector2 &position);

		virtual void ReceiveMessage(const std::string &message);

	private:
		//Holds all the entities currently in the scene
		std::list<Entity*> entities;

		//All the entities that will be added at the end of the frame
		std::list<Entity*> toAdd;

		//All the entities that will be removed at the end of the frame
		std::list<Entity*> toRemove;

		//The map of entities sorted by tag
		std::map<std::string, std::list<Entity*> > tagMap;

		//Resolves all entities to be added or removed
		void ResolveEntityChanges();
	};
}