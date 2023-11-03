#pragma once
#include "AComponent.h"
#include "box2d/b2_fixture.h"
#include "ICollisationable.h"

namespace LeTurfu {

	class Collider : public AComponent, public ICollisationable
	{
	protected:
		b2Fixture* fixture;
	public:
		b2FixtureDef fixtureDef;
		Collider();
		void CreateFixture2d(b2Body* body);
		virtual b2Shape* GetShape();

		virtual void BeginContact(Collision* contact) override;
		virtual void EndContact(Collision* contact) override;
	};

}
