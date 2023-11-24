#include "Collider.h"
#include "Entity.h"
#include "Application.h"
#include "LuaScript.h"

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
    Entity* entityParent = Application::GetInstance()->FindEntityparent(this);
    entityParent->GetComponent<LuaScript>()->OnBeginContact();
}

void LeTurfu::Collider::EndContact(Collision* collision)
{
}
