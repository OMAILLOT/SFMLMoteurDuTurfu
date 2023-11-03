#pragma once
#include <box2d/b2_world_callbacks.h>
#include "Collision.h"

namespace LeTurfu {

class ICollisationable
{
public :

	virtual void BeginContact(Collision* collision) = 0;
	virtual void EndContact(Collision* collision) = 0;
};


}