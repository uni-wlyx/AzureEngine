#include <iostream>
#include <Azure.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Azure/Editor/EditorLayer.h"

#include <SDL.h>


// int main()
// {
// 	SDL_Window *window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
// 	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
// 	bool quit = false;
// 	SDL_Event event;
 
// 	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
// 	while (!quit) {
// 		while (SDL_PollEvent(&event)) {
// 			switch (event.type) {
// 			case SDL_QUIT:
// 				quit = true;
// 				break;
// 			case SDL_MOUSEMOTION:
// 				if (SDL_GetMouseState(NULL, NULL) &SDL_BUTTON(1))
// 					SDL_RenderDrawPoint(renderer, event.motion.x, event.motion.y);
// 				break;
// 			}
// 		}
 
// 		SDL_RenderPresent(renderer);
// 		SDL_Delay(1000 / 60); 
// 	}
// 	SDL_DestroyWindow(window);
// 	SDL_DestroyRenderer(renderer);
// 	return 0;
// }

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
