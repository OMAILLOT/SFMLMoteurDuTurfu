#include "Collision.h"

b2Body* LeTurfu::Collision::GetCurrentRigibody()
{
    return currentRigibody;
}

b2Body* LeTurfu::Collision::GetOtherRigibody()
{
    return otherRigibody;
}

void LeTurfu::Collision::SetCurrentRigiBody(b2Body* newBody)
{
    currentRigibody = newBody;
}

void LeTurfu::Collision::SetOtherRigibody(b2Body* newBody)
{
    otherRigibody = newBody;
}

void LeTurfu::Collision::BeginContact(b2Contact* contact)
{
}

void LeTurfu::Collision::EndContact(b2Contact* contact)
{
}
