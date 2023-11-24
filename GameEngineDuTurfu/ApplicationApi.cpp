#include "ApplicationApi.h"

LeTurfu::ApplicationApi::ApplicationApi(Application* _app)
{
    app = _app;
    window = &app->window;
}

LeTurfu::EntityApi* LeTurfu::ApplicationApi::FindEntityParent(AComponent* currentComponent)
{
    return app->FindEntityApiParent(currentComponent);
}

LeTurfu::EntityApi* LeTurfu::ApplicationApi::GetEntityByName(std::string name)
{
    return app->GetEntityApiByName(name);
}

void LeTurfu::ApplicationApi::CloseWindow()
{
    app->CloseWindow();
}
