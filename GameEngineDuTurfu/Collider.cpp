#include "Collider.h"

LeTurfu::Collider::Collider()
{
    GenerateID();
    fixtureDef = b2FixtureDef();
    fixture = nullptr;
}

void LeTurfu::Collider::CreateFixture2d(b2Body* body)
{
    b2Shape* shape = GetShape();
    fixture = body->CreateFixture(shape, fixtureDef.density);
}

b2Shape* LeTurfu::Collider::GetShape()
{
    return nullptr;
}

void LeTurfu::Collider::BeginContact(Collision* collision)
{
}

void LeTurfu::Collider::EndContact(Collision* collision)
{
}
