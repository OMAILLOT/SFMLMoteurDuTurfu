#pragma once
#include "AComponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteRendererComponent.h"
#include "Application.h"
#include "Rigibody.h"

namespace LeTurfu {
	class CharacterController : public AComponent
	{

	protected:
		sf::RenderWindow* window;
		sf::Texture texture;
		sf::Transformable* transform;
		b2Vec2* rbMovement;

	public:
		bool canMove;
		sf::Vector2f baseMovement = sf::Vector2f(0.1f,.1f);
		float maxSpeed = 3;
		float speedIncrease = 0.1f;
		float rotateSpeed = 0;
		float speed = 0.01f;
		bool isRotate;
		sf::Vector2f PlayerPosition;

		CharacterController();
		void Init();

		virtual void Update(float deltaTime) override;
		void MoveEntity(float deltaTime);
		void DetectBorder();
		void CoinTouch();
		virtual void GenerateID() override;
	};
}