#include "CameraComponent.h"

LeTurfu::CameraComponent::CameraComponent()
{
	LeTurfu::Application* app = LeTurfu::Application::GetInstance();

	view.setSize((sf::Vector2f)app->window.getSize());

	view.setCenter(app->window.getSize().x / 2, app->window.getSize().y / 2);

	app->window.setView(view);
}

void LeTurfu::CameraComponent::Update(float deltaTime)
{
	LeTurfu::Application* app = LeTurfu::Application::GetInstance();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && currentZoom > maxZoom) {
		currentZoom -= zoomSpeed;
		view.zoom(1-zoomSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && currentZoom < maxDezoom) {
		currentZoom += zoomSpeed;
		view.zoom(1+zoomSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		view.rotate(rotationSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		view.rotate(-rotationSpeed);
	}

	app->window.setView(view);
	//view.setCenter(app->window.getSize().x / 2, app->window.getSize().y / 2);
}

void LeTurfu::CameraComponent::GenerateID()
{
	ID = 1126644564646;
}
