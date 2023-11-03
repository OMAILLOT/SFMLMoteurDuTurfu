#pragma once
#include "box2d/b2_body.h"
#include "Entity.h"
#include "Application.h"
#include "Collider.h"

namespace LeTurfu {

class Rigibody : public AComponent
{
protected:
	b2BodyDef bodyDef;
	b2Body* body;
	Entity* entityParent;
public:
	Rigibody();
	void Init();

	//SETTER
	void SetBodyType(b2BodyType bodyType);
	void SetBodyPosition(b2Vec2 bodyPosition);
	void SetLinearVelocity(b2Vec2 linearVelocity);
	void SetAngularVelocity(b2Vec2 angularVelocity);

	//GETTER
	b2Vec2 GetBodyPosition();
	float GetBodyAngle();
	b2Vec2 GetLinearVelocity();
	b2Vec2 GetAngularVelocity();
	b2Body* GetBody();
};

}
