#include "pch.h"
#include "AComponent.h"
#include "Application.h"

LeTurfu::AComponent::AComponent()
{
	GenerateID();
}

void LeTurfu::AComponent::Awake()
{
	
}

void LeTurfu::AComponent::Start()
{
}

void LeTurfu::AComponent::Update(float deltaTime)
{
}

void LeTurfu::AComponent::LateUpdate()
{
}

void LeTurfu::AComponent::GenerateID()
{
	ID = LeTurfu::Application::GetInstance()->GenerateID();
}

void LeTurfu::AComponent::Draw()
{
}

//LeTurfu::AComponent::AComponent()
//{
//	std::string finalResult;
//	for (int i = 0; i < 9; i++) {
//		finalResult += std::rand() % 9;
//	}
//
//	ID = std::stoi(finalResult);
//	std::cout << ID << std::endl;
//}
