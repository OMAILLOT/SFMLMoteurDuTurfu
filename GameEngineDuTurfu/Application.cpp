#include "Application.h"


LeTurfu::Application* LeTurfu::Application::instance = nullptr;;

LeTurfu::Application* LeTurfu::Application::GetInstance()
{
    if (instance == nullptr) {
        instance = new Application();
    } 
    return instance;
}

LeTurfu::Application::Application()
{
    physics = new Physics();
    physics->Init();
}

int LeTurfu::Application::Init()
{
    window.create(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Fullscreen);

    return 0;
}

void LeTurfu::Application::AllUpdate()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        clock.restart();

        float deltatime = clock.getElapsedTime().asSeconds();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(currentColor);


        for (LeTurfu::Entity* entity : allEntity) {
            entity->Update(deltatime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        physics->UpdatePhysics(deltatime);

        window.display();
    }
}

void LeTurfu::Application::OpenWindow()
{

}

void LeTurfu::Application::CloseWindow()
{
}

LeTurfu::Entity* LeTurfu::Application::CreateEntity()
{
    Entity* entity = new Entity();
    allEntity.push_back(entity);
    return entity;
}

void LeTurfu::Application::CreateComponent()
{
}

void LeTurfu::Application::ChangeColorBackground()
{
    currentColor = allColor[std::rand() % allColor.size()];
}

LeTurfu::Physics* LeTurfu::Application::GetPhysics()
{
    return physics;
}

LeTurfu::Entity* LeTurfu::Application::FindEntityparent(AComponent* currentComponent)
{
    for (Entity* entity : allEntity) {

        for (AComponent* component : entity->allComponents) {
            if (component->ID == currentComponent->ID) {
                return entity;
            }
        }
    }
}

int LeTurfu::Application::GenerateID()
{
    genericID++;
    return genericID;
}
