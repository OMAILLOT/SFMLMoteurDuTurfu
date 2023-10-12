#pragma once
#include <iostream>
#include <string>
#include "Entity.h"
namespace LeTurfu {

class AComponent
{
protected:
public:
	Entity& entityParent;
	int ID;
	AComponent(Entity& entity);
	virtual void Awake();
	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void LateUpdate();
	virtual void GenerateID();
};

}
