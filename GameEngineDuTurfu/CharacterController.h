#pragma once
#include "AComponent.h"
#include "Application.h"

namespace LeTurfu {
	class CharacterController : public AComponent
	{
	public:

		sf::Vector2f baseMovement = sf::Vector2f(0.1f,.1f);
		float maxSpeed;
		float speedIncrease = 0;
		float rotateSpeed;
		bool isRotate;

		CharacterController(Entity& entity);
		virtual void Update(float deltaTime) override;
		void MoveEntity();
		void DetectBorder();
		void CoinTouch();
		virtual void GenerateID() override;
	};
}