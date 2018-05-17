#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <SDL.h>
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

	//Initialise the font
	TTF_Font* font = NULL;	

	//Defining surface to hold text
	SDL_Surface* textSurface = NULL;

	//Defining the texture used to create the text
	SDL_Texture* textTexture = NULL;	

	//Declare time floats to calculate the fps
	float lastTime, currentTime, deltaTime;
	int currentFps;

	//Value to store how many frames have passed;
	int frames;

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

		//Set the font
		font = TTF_OpenFont("../Include/Fonts/arial.ttf", 25);

		//If the window fails to be created, exit the program
		if (window == NULL)
		{
			std::cout << "Window could not be created." << std::endl;
			return -1;
		}

		//Exit if the Renderer fails to be created
		else if (renderer == NULL)
		{
			std::cout << "Renderer could not be created." << std::endl;
			return -1;
		}

		//Exit if the font does not exist
		else if (font == NULL)
		{
			std::cout << "Could not get font" << std::endl << TTF_GetError();
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
			ParticleController pController(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
			
			//Set the initial number of particles
			pController.SetParticleNum(2000);

			//Create the particles now the number of particles is set
			pController.CreateParticles();

			//Define the rect to hold the text and FPS val
			SDL_Rect textRect;
			textRect.x = 10;
			textRect.y = 10;
			textRect.w = 50;
			textRect.h = 25;

			//Initialise font colour
			SDL_Color fontColour = { 0, 255, 255 };

			//Initialise the time for calculating the fps
			lastTime = 0;
			currentTime = 0;
			deltaTime = 0;
			currentFps = 0;
			frames = 0;


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
							std::cout << "Key Pressed" << std::endl;
							switch (inputEvent.key.keysym.sym)
							{								
								case SDLK_UP:
								{
									if (pController.GetParticleNum() < 10000)
									{
										pController.IncreaseParticleNum();
										pController.CreateParticles();
									}
									break;
								}
								case SDLK_DOWN:
								{
									if (pController.GetParticleNum() > 2000)
									{
										pController.DecreaseParticleNum();
										pController.CreateParticles();
									}
									break;
								}
								case SDLK_SPACE:
								{
									if (pController.GetState() == Standard)
									{
										pController.DivideParticles();
									}
									break;
								}
								case SDLK_1:
								{
									pController.SetCollidingDivision(0);
									break;
								}
								case SDLK_2:
								{
									pController.SetCollidingDivision(1);
									break;
								}
								case SDLK_3:
								{
									pController.SetCollidingDivision(2);
									break;
								}
								case SDLK_4:
								{
									pController.SetCollidingDivision(3);
									break;
								}
								case SDLK_5:
								{
									pController.SetCollidingDivision(4);
									break;
								}
								case SDLK_6:
								{
									pController.SetCollidingDivision(5);
									break;
								}
								case SDLK_7:
								{
									pController.SetCollidingDivision(6);
									break;
								}
								case SDLK_8:
								{
									pController.SetCollidingDivision(7);
									break;
								}
								case SDLK_ESCAPE:
								{
									ProgramActive = false;
									break;
								}
							}
						}
					}
				}

				//Calculate deltaTime for fps
				currentTime = SDL_GetTicks();
				deltaTime = currentTime - lastTime;
				lastTime = currentTime;
				currentFps = frames / (currentTime / 1000); 
				
				//Render fps text to screen
				std::string fpsPrefix = "FPS: ";
				std::string fpsText;
				fpsText = fpsPrefix + std::to_string(currentFps);

				//Clear the screen
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);

				if (pController.GetState() == Divided || pController.GetState() == Colliding)
				{
					//std::cout << "Particles divided cleanly" << std::endl;
					pController.DrawDivisions();
				}			

				//Perform particle functions
				pController.MoveParticles();
				
				if (pController.GetState() == Colliding)
				{
					pController.CheckCollisions();
				}

				pController.DrawParticles();


				//Draw the text
				textSurface = TTF_RenderText_Solid(font, fpsText.c_str(), fontColour);
				textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
				SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
				
				//Render the screen
				SDL_RenderPresent(renderer);

				//Update the number of frames
				frames++;

				//Delay(0.0125f);
			}
		}
	}	

	//Wait two seconds
	Delay(0.5f);

	//Destroy the renderer
	SDL_DestroyRenderer(renderer);

	//Free the screen surface
	SDL_FreeSurface(screenSurface);

	/*//Free the text surface
	//SDL_FreeSurface(textSurface);

	//Destroy text texture
	//SDL_DestroyTexture(textTexture);

	//Close the font
	//TTF_CloseFont(font);*/

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