#pragma once
#include "AComponent.h"
#include "Application.h"
#include "SpriteRendererComponent.h"
#include <iostream>

namespace LeTurfu {
	class CharacterController : public AComponent
	{
	public:

		sf::Vector2f baseMovement = sf::Vector2f(0.1f,.1f);
		float maxSpeed = 3;
		float speedIncrease = 0.1f;
		float rotateSpeed = 0;
		float speed = 0.01f;
		bool isRotate;
		sf::Vector2f PlayerPosition;

		CharacterController();

		virtual void Update(float deltaTime) override;
		void MoveEntity();
		void DetectBorder();
		void CoinTouch();
		virtual void GenerateID() override;
	};
}