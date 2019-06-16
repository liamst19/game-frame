/** medialayer_sdl_drawing_renderer.cpp
 *
 *  Might be better to use SDL_gfx library
 */

#include "medialayer_sdl_drawing_renderer.h"

#include <SDL2/SDL.h>
// #include "../include/SDL2/SDL2_gfxPrimitives.h"

MediaLayer_SDL_Drawing_Renderer::MediaLayer_SDL_Drawing_Renderer()
{
}

MediaLayer_SDL_Drawing_Renderer::~MediaLayer_SDL_Drawing_Renderer()
{
    free();
}

bool MediaLayer_SDL_Drawing_Renderer::initialize(SDL_Renderer* renderer, SDL_Window* window)
{

	_renderer = renderer;
	_window = window;	

	return true;
}

// Free resources
void MediaLayer_SDL_Drawing_Renderer::free()
{
    _renderer = nullptr;
    _window = nullptr;
}

// Render point
bool MediaLayer_SDL_Drawing_Renderer::render_point(int x, int y, int r, int g, int b, int alpha)
{
    int result = 0;
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);
	result |= SDL_RenderDrawPoint(_renderer, x, y);
    return result == 0;
}

// Render line
bool MediaLayer_SDL_Drawing_Renderer::render_line(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, int thickness)
{
    int result = 0;
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);	
	result |= SDL_RenderDrawLine(_renderer, aX, aY, bX, bY);
    return result == 0;
}

// Render rectangle outline
bool MediaLayer_SDL_Drawing_Renderer::render_rectangle(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill)
{
    int result = 0;
	int tmp;
	SDL_Rect rect;

	/*
	* Test for special cases of straight lines or single point 
	*/
	if (aX == bX) {
		if (aY == bY) {
			return (render_point(aX, aY, r, g, b, alpha));
		} else {
			return (render_line(aX, aY, bX, bY, r, g, b, alpha));
		}
	} else {
		if (aY == bY) {
			return (render_line(aX, aY, bX, bY, r, g, b, alpha));
		}
	}

	/*
	* Swap aX, bX if required 
	*/
	if (aX > bX) {
		tmp = aX;
		aX = bX;
		bX = tmp;
	}

	/*
	* Swap aY, bY if required 
	*/
	if (aY > bY) {
		tmp = aY;
		aY = bY;
		bY = tmp;
	}

	/* 
	* Create destination rect
	*/	
	rect.x = aX;
	rect.y = aY;
	rect.w = bX - aX;
	rect.h = bY - aY;
	
	/*
	* Draw
	*/
	result = 0;
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);	
	result |= SDL_RenderDrawRect(_renderer, &rect);
    return result == 0;
}

// Render circle
bool MediaLayer_SDL_Drawing_Renderer::render_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha, bool fill)
{
    return render_ellipse(centerX, centerY, centerX, centerY, radius, r, g, b, alpha); 
}

// Render ellipse
bool MediaLayer_SDL_Drawing_Renderer::render_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill)
{
    int result = 0;

    return result == 0;
}