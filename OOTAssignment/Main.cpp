#include <iostream>
#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_POSX = 50;
const int SCREEN_POSY = 50;

int main(int argc, char* args[])
{
	//Defining the window we will render to
	SDL_Window* window = NULL;

	//Defining the surface contained by the window
	SDL_Surface* screenSurface = NULL;	
	
	//Exit the program if SDL cannot be initialised
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialise." << std::endl;
		return -1;
	}

	//If no error occurs, carry on with defining the window
	else
	{
		window = SDL_CreateWindow("Particle Program", SCREEN_POSX, SCREEN_POSY, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		//If the window fails to be created, exit the program
		if (window == NULL)
		{
			std::cout << "Window could not be created." << std::endl;
		}

		else
		{
			//Get the window's surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface in as white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}