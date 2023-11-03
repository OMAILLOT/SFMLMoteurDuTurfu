#pragma once
#include"box2d/b2_body.h"
#include "CollisionListener.h"

namespace LeTurfu {

class Collision
{
protected:
	b2Body* currentRigibody;
	b2Body* otherRigibody;

public :
	b2Body* GetRbA();
	b2Body* GetRbB();

	void SetCurrentRigiBody(b2Body* newBody);
	void SetOtherRigibody(b2Body* newBody);
};

}
