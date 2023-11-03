#include "CollisionListener.h"
#include <iostream>
#include "box2d/b2_contact.h"
#include "Application.h"
#include "ICollisationable.h"
#include "Collider.h"

void LeTurfu::CollisionListener::BeginContact(b2Contact* contact)
{
	Application* app = Application::GetInstance();

	for (AComponent* comp : app->allComponent) {

		if (Collider* compCast = dynamic_cast<Collider*>(comp)) {

			//if (dynamic_cast<Collider*>(contact) == compCast) {

			//}
				Collision* collision = new Collision();
				collision->SetCurrentRigiBody(contact->GetFixtureA()->GetBody());
				collision->SetOtherRigibody(contact->GetFixtureB()->GetBody());
				
				compCast->BeginContact(collision);
				std::cout << "Collision" << std::endl;
		}
	}
	



	//void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	//if (bodyUserData)
}

void LeTurfu::CollisionListener::EndContact(b2Contact* contact)
{
	std::cout << "EndColision" << std::endl;
}
