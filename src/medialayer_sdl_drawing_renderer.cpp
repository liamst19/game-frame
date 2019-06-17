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
bool MediaLayer_SDL_Drawing_Renderer::render_point(
		int x, int y, 
		int r, int g, int b, int alpha)
{
    int result = 0;
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);
	result |= SDL_RenderDrawPoint(_renderer, x, y);
    return result == 0;
}

// Render line
bool MediaLayer_SDL_Drawing_Renderer::render_line(
		int aX, int aY, 
		int bX, int bY, 
		int r, int g, int b, int alpha, 
		int thickness)
{
    int result = 0;
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);	
	result |= SDL_RenderDrawLine(_renderer, aX, aY, bX, bY);
    return result == 0;
}

// Render rectangle outline
bool MediaLayer_SDL_Drawing_Renderer::render_rectangle(
		int aX, int aY, 
		int bX, int bY, 
		int r, int g, int b, int alpha, 
		bool fill)
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
bool MediaLayer_SDL_Drawing_Renderer::render_circle(
			int centerX, int centerY, 
			int radius, 
			int r, int g, int b, int alpha, 
			bool fill)
{
    return render_ellipse(centerX, centerY, radius, radius, r, g, b, alpha); 
}

// Render ellipse
// (aX, aY) and (bX, bY) represent the two focii of ellipse.
// radiusX and radiusY are horizontal and vertical radius of
// the ellipse, respecively.
bool MediaLayer_SDL_Drawing_Renderer::render_ellipse(
			int x, int y,
            int radiusX, int radiusY, 
			int r, int g, int b, int alpha, 
			bool fill)
{

	// Radii less than zero is not a shape
	if (radiusX < 0 || radiusY < 0)
	{
		return false;
	}

	// Special cases for horizontal/vertical line, or single point
	if(radiusX == 0)
	{
		if(radiusY == 0)
		{
			return render_point(x, y, r, g, b, alpha);
		} else
		{
			return render_line(x, y - radiusY, x, y + radiusY, r, g, b, alpha); // vertical line
		}
	} else if(radiusY == 0)
	{
		return render_line(x - radiusX, y, x + radiusX, y, r, g, b, alpha); // horizontal line
	}

	// ------------------------------

    int result = 0;
	int rXi, rYi;
	int rx2, ry2, rx22, ry22; 
    int error;
    int curX, curY, curXp1, curYm1;
	int scrX, scrY, oldX, oldY;
    int deltaX, deltaY;
	int ellipseOverscan;

	// Set Color
	result |= SDL_SetRenderDrawBlendMode(_renderer, (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
	result |= SDL_SetRenderDrawColor(_renderer, r, g, b, alpha);	

	rXi = radiusX;
	rYi = radiusY;

	// adjust overscan
	ellipseOverscan = _ellipse_adjust_overscan(rXi, rYi);

	// Top/bottom center points
	oldX = scrX = 0;
	oldY = scrY = rYi;
	result |= _draw_quadrants(x, y, 0, radiusY, fill);

	// Midpoint ellipse algorithm with overdraw
	rXi *= ellipseOverscan;
	rYi *= ellipseOverscan;
	rx2 = rXi * rXi;
	rx22 = rx2 + rx2;
    ry2 = rYi * rYi;
	ry22 = ry2 + ry2;
    curX = 0;
    curY = rYi;
    deltaX = 0;
    deltaY = rx22 * curY;

	// Points in segment 1 
    error = ry2 - rx2 * rYi + rx2 / 4;
    while (deltaX <= deltaY)
    {
          curX++;
          deltaX += ry22;
 
          error +=  deltaX + ry2; 
          if (error >= 0)
          {
               curY--;
               deltaY -= rx22; 
               error -= deltaY;
          }

		  scrX = curX / ellipseOverscan;
		  scrY = curY / ellipseOverscan;
		  if ((scrX != oldX && scrY == oldY) || (scrX != oldX && scrY != oldY)) {
			result |= _draw_quadrants(x, y, scrX, scrY, fill);
			oldX = scrX;
			oldY = scrY;
		  }
    }

	// Points in segment 2
	if (curY > 0) 
	{
		curXp1 = curX + 1;
		curYm1 = curY - 1;
		error = ry2 * curX * curXp1 + ((ry2 + 3) / 4) + rx2 * curYm1 * curYm1 - rx2 * ry2;
		while (curY > 0)
		{
			curY--;
			deltaY -= rx22;

			error += rx2;
			error -= deltaY;
 
			if (error <= 0) 
			{
               curX++;
               deltaX += ry22;
               error += deltaX;
			}

		    scrX = curX / ellipseOverscan;
		    scrY = curY / ellipseOverscan;
		    if ((scrX != oldX && scrY == oldY) || (scrX != oldX && scrY != oldY)) {
				oldY--;
				for (;oldY >= scrY; oldY--) {
					result |= _draw_quadrants(x, y, scrX, oldY, fill);
					/* prevent overdraw */
					if (fill) {
						oldY = scrY - 1;
					}
				}
  				oldX = scrX;
				oldY = scrY;
		    }		
		}

		/* Remaining points in vertical */
		if (!fill) {
			oldY--;
			for (;oldY >= 0; oldY--) {
				result |= _draw_quadrants(x, y, scrX, oldY, fill);
			}
		}
	}

    return result == 0;
}

int MediaLayer_SDL_Drawing_Renderer::_ellipse_adjust_overscan(int rXi, int rYi)
{
	const int default_ellipse_overscan = 4;

	if(rXi >= 512 || rYi >= 512)
	{
		return default_ellipse_overscan / 4;
	} 
	else if(rXi >= 256 || rYi >= 256)
	{
		return default_ellipse_overscan / 2;
	} 
	else
	{
		return default_ellipse_overscan;
	}	
}

int MediaLayer_SDL_Drawing_Renderer::_draw_quadrants(int x, int y, int dx, int dy, bool fill)
{
	int result = 0;
	int xpdx, xmdx;
	int ypdy, ymdy;

	if (dx == 0) {
		if (dy == 0) {
			result |= SDL_RenderDrawPoint(_renderer, x, y);
		} else {
			ypdy = y + dy;
			ymdy = y - dy;
			if (fill) {
				result |= SDL_RenderDrawLine(_renderer, x, ymdy, x, ypdy);
			} else {
				result |= SDL_RenderDrawPoint(_renderer, x, ypdy);
				result |= SDL_RenderDrawPoint(_renderer, x, ymdy);
			}
		}
	} else {	
		xpdx = x + dx;
		xmdx = x - dx;
		ypdy = y + dy;
		ymdy = y - dy;
		if (fill) {
				result |= SDL_RenderDrawLine(_renderer, xpdx, ymdy, xpdx, ypdy);
				result |= SDL_RenderDrawLine(_renderer, xmdx, ymdy, xmdx, ypdy);
		} else {
				result |= SDL_RenderDrawPoint(_renderer, xpdx, ypdy);
				result |= SDL_RenderDrawPoint(_renderer, xmdx, ypdy);
				result |= SDL_RenderDrawPoint(_renderer, xpdx, ymdy);
				result |= SDL_RenderDrawPoint(_renderer, xmdx, ymdy);
		}
	}
	return result;
}