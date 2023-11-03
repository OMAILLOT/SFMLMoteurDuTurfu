#pragma once
#include <box2d/b2_world_callbacks.h>

namespace LeTurfu {

class ICollisationable
{

	virtual void BeginCollision();
	virtual void EndCollision();

	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact) ;
};


}