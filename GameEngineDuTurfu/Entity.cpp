#include "Entity.h"
#include "Application.h"

void LeTurfu::Entity::Awake()
{
	setScale(.1f, .1f);
}

void LeTurfu::Entity::Start()
{
}

void LeTurfu::Entity::Update(float deltaTime)
{
	for (AComponent* component : allComponents) {
		component->Update(deltaTime);
	}
}

void LeTurfu::Entity::LateUpdate()
{
}

LeTurfu::Entity::Entity(std::string _name)
{
	name = _name;
	Awake();
}

std::string LeTurfu::Entity::GetName()
{
	return name;
}

LeTurfu::AComponent* LeTurfu::Entity::addComponent(AComponent* component)
{
	allComponents.push_back(component);
	Application::GetInstance()->allComponent.push_back(component);
	return component;
}

void LeTurfu::Entity::setVectorPosition(sf::Vector2f v)
{
	setPosition(v);
}

//LeTurfu::AComponent* LeTurfu::Entity::GetComponent(AComponent* component)
//{
//	for (AComponent* _component : allComponents) {
//		if (_component->ID == component->ID) {
//			return _component;
//		}
//	}
//}