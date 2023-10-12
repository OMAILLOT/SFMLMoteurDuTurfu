#pragma once
#include <Application.h>
#include <Entity.h>

int main()
{
    LeTurfu::Entity* newEntity = LeTurfu::Application::GetInstance()->CreateEntity();
    LeTurfu::Application::GetInstance()->Init();


    newEntity->speedIncrease = 0;
    newEntity->baseMovement = sf::Vector2f(.1f, .1f);
    newEntity->speedRotate = 0;
}
