#include "Collision.h"

b2Body* LeTurfu::Collision::GetRbA()
{
    return currentRigibody;
}

b2Body* LeTurfu::Collision::GetRbB()
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

