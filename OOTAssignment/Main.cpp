#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_POSX = 50;
const int SCREEN_POSY = 50;

//Declare all the functions
void Delay(int seconds);

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
	if (TTF_Init() < 0)
	{
		std::cout << "TTF could not initialise." << std::endl;
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

			//Fill the surface in as black
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));

			//Update the surface
			SDL_UpdateWindowSurface(window);			
		}
	}

	//Set the boolean to check if the program should exit
	bool ProgramActive = true;

	while (ProgramActive)
	{
		SDL_Event inputEvent;

		while (SDL_PollEvent(&inputEvent))
		{
			switch (inputEvent.type)
			{
				case SDL_KEYDOWN:
				{
					case SDLK_ESCAPE:
						ProgramActive = false;
				}
			}
		}
	}

	//Wait two seconds
	Delay(2);

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

//Enter the number of seconds to delay the program
void Delay(int seconds)
{
	SDL_Delay(seconds * 1000);
}