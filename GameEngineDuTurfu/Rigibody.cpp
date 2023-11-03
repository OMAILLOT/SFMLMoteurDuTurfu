#include "Rigibody.h"

LeTurfu::Rigibody::Rigibody()
{
    entityParent = nullptr;
}

void LeTurfu::Rigibody::Init()
{
    bodyDef = b2BodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);

    body = Application::GetInstance()->GetPhysics()->GetWorld()->CreateBody(&bodyDef);

    entityParent = LeTurfu::Application::GetInstance()->FindEntityparent(this);

    entityParent->GetComponent<Collider>()->CreateFixture2d(body);

    
}

void LeTurfu::Rigibody::SetBodyType(b2BodyType _bodyType)
{
    body->SetType(_bodyType);
}

void LeTurfu::Rigibody::SetBodyPosition(b2Vec2 bodyPosition)
{
    body->SetTransform(bodyPosition, body->GetAngle());
    //entityParent = LeTurfu::Application::GetInstance()->FindEntityparent(this);

    //entityParent->GetComponent<Collider>()->fixtureDef.density = .5f;
}

void LeTurfu::Rigibody::SetLinearVelocity(b2Vec2 linearVelocity)
{
    body->SetLinearVelocity(linearVelocity);
}

void LeTurfu::Rigibody::SetAngularVelocity(b2Vec2 angularVelocity)
{
    body->SetAngularVelocity(angularVelocity.Normalize());
}

b2Vec2 LeTurfu::Rigibody::GetBodyPosition()
{
    return body->GetTransform().p;

}

float LeTurfu::Rigibody::GetBodyAngle()
{
    return body->GetAngle();
}

b2Vec2 LeTurfu::Rigibody::GetLinearVelocity()
{
    return b2Vec2();
}

b2Vec2 LeTurfu::Rigibody::GetAngularVelocity()
{
    return b2Vec2();
}

b2Body* LeTurfu::Rigibody::GetBody()
{
    return body;
}
