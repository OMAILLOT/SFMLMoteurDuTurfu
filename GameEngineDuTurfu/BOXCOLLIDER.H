#pragma once
#include "Collider.h"
#include "box2d/b2_polygon_shape.h"

namespace LeTurfu {

class BoxCollider : public Collider
{
protected:
	b2PolygonShape* boxShape;
	float shapeSize = 10;

public:
	float density;
	BoxCollider();
	void Init();
	virtual b2Shape* GetShape() override;
	void SetShapeSize(float size);
};

}

