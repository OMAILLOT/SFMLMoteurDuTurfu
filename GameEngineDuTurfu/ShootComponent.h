#pragma once
#include "AComponent.h"
#include "Entity.h"

namespace LeTurfu{


class ShootComponent : public AComponent
{
public:
	std::vector<Entity> bulletInstantiate;
	Entity* bullet;

	ShootComponent();

	void SetBullet(Entity* entity);
	virtual void Update(float deltaTime) override;
	virtual void GenerateID() override;
	void Shoot();
};

}
