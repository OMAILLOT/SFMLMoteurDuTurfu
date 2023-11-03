#pragma once
#include "box2d/b2_world_callbacks.h"
///#include <b2_world_callbacks.h>

namespace LeTurfu {

class CollisionListener : public b2ContactListener
{
	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;
};

}
