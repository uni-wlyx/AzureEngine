#include <iostream>
#include <Azure.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Azure/Editor/EditorLayer.h"

#include <SDL.h>

int main()
{

	float a = 1.23124;
    Azure::AzureLog::Init();

    AZ_CORE_INFO("Init Log");

    auto *app = Azure::Application::CreateApp();
    app->PushOverlay(new Azure::EditorLayer());
    //    app->PushOverlay(new Azure::ImGuiLayer());
    app->Run();
    delete app;

    return 0;
}
