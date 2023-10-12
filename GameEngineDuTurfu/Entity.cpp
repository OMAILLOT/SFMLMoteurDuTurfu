#include "Entity.h"
#include "Application.h"

void LeTurfu::Entity::Awake()
{
}

void LeTurfu::Entity::Start()
{
}

void LeTurfu::Entity::Update(float deltaTime)
{
	for (AComponent component : allComponents) {
		component.Update(deltaTime);
	}
}

void LeTurfu::Entity::LateUpdate()
{
}

LeTurfu::Entity::Entity()
{
	Awake();
}

LeTurfu::AComponent& LeTurfu::Entity::addComponent(AComponent component)
{
	allComponents.push_back(component);
	return component;
}

LeTurfu::AComponent& LeTurfu::Entity::GetComponent(AComponent component)
{
	for (AComponent _component : allComponents) {
		if (_component.ID == component.ID) {
			return _component;
		}
	}
}



