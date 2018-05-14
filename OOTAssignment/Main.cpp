#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>

#include "ParticleController.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int SCREEN_POSX = 50;
const int SCREEN_POSY = 50;

//Declare all the functions
void Delay(float seconds);

int main(int argc, char* args[])
{
	//Defining the window we will render to
	SDL_Window* window = NULL;

	//Defining the renderer for rendering to the screen
	SDL_Renderer* renderer = NULL;

	//Defining the surface contained by the window
	SDL_Surface* screenSurface = NULL;	
	
	/*//Defining surface to hold text
	SDL_Surface* textSurface = NULL;

	//Defining the texture used to create the text
	SDL_Texture* textTexture = NULL;

	//Defining the font used throughout the program
	TTF_Font* font = TTF_OpenFont("Arial.ttf", 25);

	//Defining the font colour
	SDL_Color fontBGColour = { 255, 255, 255 };
	SDL_Color fontFGColour = { 0, 0, 255 };

	textSurface = TTF_RenderText_Shaded(font, "This is my text.", fontFGColour, fontFGColour);
	SDL_Rect textLocation = { 50, 50, 0, 0 }; */

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
		//Create the window
		window = SDL_CreateWindow("Particle Program", SCREEN_POSX, SCREEN_POSY, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		//Create the renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		//If the window fails to be created, exit the program
		if (window == NULL)
		{
			std::cout << "Window could not be created." << std::endl;
			return -1;
		}

		if (renderer == NULL)
		{
			std::cout << "Renderer could not be created." << std::endl;
			return -1;
		}

		else
		{
			//Get the window's surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface in as black
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));

			//Update the surface
			SDL_UpdateWindowSurface(window);	

			//Create the particle controller to control the way the particles work and react
			ParticleController pController(renderer);
			
			//Set the initial number of particles
			pController.SetParticleNum(2000);

			//Create the particles now the number of particles is set
			pController.CreateParticles();

			//Set the boolean to check if the program should exit
			bool ProgramActive = true;

			//The main program procedure
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

				//Enter the program text

				//Draw the current state of the program
				
				//Wait for input

				pController.DrawParticles();

				
				SDL_RenderPresent(renderer);

			}
		}
	}	

	//Wait two seconds
	Delay(0.5f);

	//Destroy the renderer
	SDL_DestroyRenderer(renderer);

	//Free the screen surface
	SDL_FreeSurface(screenSurface);

	//Free the text surface
	//SDL_FreeSurface(textSurface);

	//Destroy text texture
	//SDL_DestroyTexture(textTexture);

	//Close the font
	//TTF_CloseFont(font);

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

//Enter the number of seconds to delay the program
void Delay(float seconds)
{
	SDL_Delay(seconds * 1000);
}