#pragma once
#include "AComponent.h"
#include "SFML\Graphics.hpp"
#include "Application.h"

namespace LeTurfu {


class CameraComponent : public AComponent
{
private:
	float currentZoom = 1;

public :
	sf::View view;

	float maxZoom = .7f;
	float maxDezoom = 1.3f;
	float zoomSpeed = .001f;

	float rotationSpeed = .1f;

	CameraComponent();
	virtual void Update(float deltaTime) override;
	virtual void GenerateID() override;
};

}
