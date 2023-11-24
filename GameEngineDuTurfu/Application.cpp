#include "Application.h"
#include "EntityApi.h"
#include "Entity.h"
#include "CharacterController.h"
//#include "ApplicationApi.h"


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
    //LeTurfu::Api::ApplicationApi* appApi = new LeTurfu::Api::ApplicationApi(this);
    return 0;
}

void LeTurfu::Application::AllUpdate()
{
    sf::Clock clock;
    for (Entity* entity : allEntity)
    {
        entity->StartAllComponent();
    }

    while (window.isOpen())
    {
        //clock.restart();

        float deltatime = clock.restart().asSeconds();
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
    window.close();
}

LeTurfu::Entity* LeTurfu::Application::CreateEntity(std::string name)
{
    Entity* entity = new Entity(name);
    LeTurfu::EntityApi* entityApi = new LeTurfu::EntityApi(entity);
    allEntity.push_back(entity);
    allEntityApi.push_back(entityApi);
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
    return nullptr;
}

LeTurfu::EntityApi* LeTurfu::Application::FindEntityApiParent(AComponent* currentComponent) {

    for (EntityApi* entityApi : allEntityApi) {

        for (AComponent* component : entityApi->GetEntity()->allComponents) {
            if (component->ID == currentComponent->ID) {
                return entityApi;
            }
        }
    }

    return nullptr;
}

int LeTurfu::Application::GenerateID()
{
    genericID++;
    return genericID;
}

LeTurfu::Entity* LeTurfu::Application::GetEntityByName(std::string name)
{
    for (Entity* entity : allEntity) {
        if (entity->GetName() == name) {
            return entity;
        }
    }
    return nullptr;
}

LeTurfu::EntityApi* LeTurfu::Application::GetEntityApiByName(std::string name) {

    for (EntityApi* entity : allEntityApi) {
        if (entity->GetName() == name) {
            return entity;
        }
    }
    return nullptr;
}

//LeTurfu::Api::EntityApi* LeTurfu::Application::GetEntityApiByEntity(Entity* entity)
//{
//    for (Entity* entity : allEntity) {
//        for (Api::EntityApi* entityApi : allEntityApi) {
//
//            if (entity == entityApi->GetEntity()) {
//                return entityApi;
//            }
//        }
//    }
//    return nullptr;
//}
