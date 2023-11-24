#include "Entity.h"
#include "Application.h"
#include "EntityApi.h"

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

void LeTurfu::Entity::StartAllComponent()
{
	for (AComponent* comp : allComponents) {
		comp->Awake();
		comp->Start();
	}
}

LeTurfu::Entity::Entity(std::string _name)
{
	name = _name;
	LeTurfu::EntityApi* entityApi = new LeTurfu::EntityApi(this);
	Awake();
}

LeTurfu::Entity::~Entity()
{
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