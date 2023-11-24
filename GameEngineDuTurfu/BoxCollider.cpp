#include "BoxCollider.h"
#include "Rigibody.h"
#include "LuaScript.h"

LeTurfu::BoxCollider::BoxCollider()
{
}

void LeTurfu::BoxCollider::Init()
{
	boxShape = new b2PolygonShape();
	boxShape->SetAsBox(shapeSize, shapeSize);
	fixtureDef.shape = boxShape;
	fixtureDef.density = density;
	fixtureDef.friction = 0.3f;
}

b2Shape* LeTurfu::BoxCollider::GetShape()
{
	return boxShape;
}

void LeTurfu::BoxCollider::SetShapeSize(float size)
{
	shapeSize = size;
	boxShape->SetAsBox(shapeSize, shapeSize);
}

void LeTurfu::BoxCollider::BeginContact(Collision* collision)
{
	Collider::BeginContact(collision);
	float velocityToLose = .8f;
	float velocityToIncrease = .2f;
	b2Vec2 currentVelocityB = collision->GetRbB()->GetLinearVelocity();
	b2Vec2 currentVelocityA = collision->GetRbA()->GetLinearVelocity();

	b2Vec2 newVelocityA = b2Vec2((currentVelocityB.x * velocityToLose + currentVelocityA.x * velocityToIncrease),
		(currentVelocityB.y * velocityToLose + currentVelocityA.y * velocityToIncrease));

	b2Vec2 newVelocityB = b2Vec2(currentVelocityA.x * velocityToLose + currentVelocityB.x * velocityToIncrease,
		currentVelocityA.y * velocityToLose + currentVelocityB.y * velocityToIncrease);

	collision->GetRbB()->SetLinearVelocity(newVelocityB);

	Entity* entityParent = Application::GetInstance()->FindEntityparent(this);

	entityParent->GetComponent<Rigibody>()->movement = newVelocityA;

}
