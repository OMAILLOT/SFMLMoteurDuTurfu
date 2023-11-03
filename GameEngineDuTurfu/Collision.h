#pragma once
#include "ICollisationable.h"
#include"box2d/b2_body.h"
#include "CollisionListener.h"

namespace LeTurfu {

class Collision : public ICollisationable
{
protected:
	b2Body* currentRigibody;
	b2Body* otherRigibody;

public :
	b2Body* GetCurrentRigibody();
	b2Body* GetOtherRigibody();

	void SetCurrentRigiBody(b2Body* newBody);
	void SetOtherRigibody(b2Body* newBody);

	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;
};

}
