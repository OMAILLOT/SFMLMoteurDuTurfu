#include "BoxCollider.h"

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
