#include "CollisionListener.h"
#include <iostream>
#include "box2d/b2_contact.h"

void LeTurfu::CollisionListener::BeginContact(b2Contact* contact)
{
	
	contact->GetFixtureB()->GetBody()->SetLinearVelocity(b2Vec2(100, 100));
	//void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	//if (bodyUserData)
	std::cout << "collision" << std::endl;
}

void LeTurfu::CollisionListener::EndContact(b2Contact* contact)
{
	std::cout << "end collision" << std::endl;
}
