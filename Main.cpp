#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
#include "InputHandler.h"
#include "Command.h"
#include "IdleCommand.h"
#include "JumpingCommand.h"
#include "ClimbingCommand.h"

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// The window we'll be rendering to
SDL_Window* window = NULL;

// The surface image
SDL_Surface* image = NULL;

// The renderer
SDL_Renderer * renderer = NULL;

// The texture that will be created
SDL_Texture* texture = NULL;

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Practical 3 - Finite State Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	image = IMG_Load("spritesheet.png");
	renderer = SDL_CreateRenderer(window, -1, 0);
	texture = SDL_CreateTextureFromSurface(renderer, image);

	SDL_Event event;
	bool quit = false;

	InputHandler inputHandler;

	Animation* animation = new Animation();
	Command* idleCommand = new IdleCommand(animation);
	Command* jumpingCommand = new JumpingCommand(animation);
	Command* climbingCommand = new ClimbingCommand(animation);
	inputHandler.bindKeysToCommands(1, idleCommand);
	inputHandler.bindKeysToCommands(2, jumpingCommand);
	inputHandler.bindKeysToCommands(3, climbingCommand);

	// Set background color
	SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	SDL_RenderClear(renderer);

	//
	SDL_Rect srcRect = { 0, 0, 64, 64 };
	SDL_Rect dstRect = { 10, 10, 64, 64 };

	while (!quit)
	{
		int ticks = SDL_GetTicks();
		int tickRate = ticks / 250;
		int sprite = tickRate % 4;

		if (animation->getAnimationState() == 1) // if Jumping, set sprite to divide it by 3 sprites
			sprite = tickRate % 3;

		switch (animation->getAnimationState())
		{
		case 0:
			srcRect = { sprite * 64, 0, 64, 64 }; // IDLE
			break;
		case 1:
			srcRect = { sprite * 64, 192, 64, 64 }; // JUMPING
			break;
		case 2:
			srcRect = { sprite * 64, 256, 64, 64 }; // CLIMBING
			break;
		}

		while (SDL_PollEvent(&event) != NULL)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				inputHandler.handleInput(event);
			}
			else if (event.type == SDL_KEYUP)
			{
				animation->idle();
			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}