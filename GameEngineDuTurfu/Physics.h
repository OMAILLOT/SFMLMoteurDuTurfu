#pragma once
#include <box2d/b2_world.h>

namespace LeTurfu {

	class Physics
	{

	protected:
		b2Vec2 gravity;
		b2World* world;
		float timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 8;
		int32 positionIterations = 3;

	public:
		Physics();
		void Init();
		void UpdatePhysics(float deltaTime);
		b2World* GetWorld();
		static const int worldScale;
	};

}

