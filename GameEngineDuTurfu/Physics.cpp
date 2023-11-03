#include "Physics.h"
#include "Entity.h"
#include "Rigibody.h"
#include "CollisionListener.h"

LeTurfu::Physics::Physics()
{
}

void LeTurfu::Physics::Init()
{
	gravity = b2Vec2(0, 10);
	world = new b2World(gravity);

	LeTurfu::CollisionListener* collisionlistener = new LeTurfu::CollisionListener();
	world->SetContactListener(collisionlistener);
}

void LeTurfu::Physics::UpdatePhysics(float deltaTime)
{
	for (Entity* entity : LeTurfu::Application::GetInstance()->allEntity)
	{
		LeTurfu::Rigibody* rb = entity->GetComponent<Rigibody>();
		if (rb != nullptr) {
			b2Vec2 b2 = b2Vec2(entity->getPosition().x, entity->getPosition().y);

			rb->SetBodyPosition(b2);
		}

	}
		world->Step(timeStep, velocityIterations, positionIterations);

	for (Entity* entity : LeTurfu::Application::GetInstance()->allEntity)
	{
		LeTurfu::Rigibody* rb = entity->GetComponent<Rigibody>();
		if (rb != nullptr) {
			b2Vec2 b2 = b2Vec2(entity->getPosition().x, entity->getPosition().y);

			entity->setPosition(rb->GetBodyPosition().x, rb->GetBodyPosition().y);
		}
	}
}

b2World* LeTurfu::Physics::GetWorld()
{
	return world;
}
