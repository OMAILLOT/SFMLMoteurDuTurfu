#pragma once
#include "AComponent.h"
#include "box2d/b2_fixture.h"

namespace LeTurfu {

	class Collider : public AComponent
	{
	protected:
		b2Fixture* fixture;
	public:
		b2FixtureDef fixtureDef;
		Collider();
		void CreateFixture2d(b2Body* body);
		virtual b2Shape* GetShape();
	};

}
