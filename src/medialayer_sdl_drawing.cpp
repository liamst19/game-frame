/** medialayer_sdl_drawing.cpp
 *
 *  Might be better to use SDL_gfx library
 */

#include "medialayer_sdl_drawing.h"

#include <SDL2/SDL.h>

MediaLayer_SDL_Drawing::MediaLayer_SDL_Drawing(SDL_Renderer* renderer, SDL_Window* window):
_renderer(renderer),
_window(window)
{
}

MediaLayer_SDL_Drawing::~MediaLayer_SDL_Drawing()
{
    free();
}

// Free resources
void MediaLayer_SDL_Drawing::free()
{
    _renderer = nullptr;
    _window = nullptr;
}

// Render point
bool MediaLayer_SDL_Drawing::render_point(int x, int y, int r, int g, int b, int alpha)
{
    // Set Color
    SDL_SetRenderDrawColor(_renderer,
                            r, 
                            g, 
                            b, 
                            alpha);

    SDL_RenderDrawPoint(_renderer, x, y);

    return true;
}

// Render line
bool MediaLayer_SDL_Drawing::render_line(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, int thickness)
{
    // Set Color
    SDL_SetRenderDrawColor(_renderer,
                            r, 
                            g, 
                            b, 
                            alpha);

    SDL_RenderDrawLine(_renderer, aX, aY, bX, bY);

    return true;
}

// Render rectangle outline
bool MediaLayer_SDL_Drawing::render_rectangle(int aX, int aY, int w, int h, int r, int g, int b, int alpha, bool fill)
{
    // Set Color
    SDL_SetRenderDrawColor(_renderer,
                            r, 
                            g, 
                            b, 
                            alpha);

    SDL_Rect rect{aX, aY, w, h};

    SDL_RenderDrawRect(_renderer, &rect);

    return true;
}

// Render circle
bool MediaLayer_SDL_Drawing::render_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha, bool fill)
{
    // Circle is an ellipse with overlapping focii
    return render_ellipse(centerX, centerY, centerX, centerY, r, g, b, alpha, fill);
}

// Render ellipse
bool MediaLayer_SDL_Drawing::render_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill)
{
    // Set Color
    SDL_SetRenderDrawColor(_renderer,
                            r, 
                            g, 
                            b, 
                            alpha);

    // Draw Ellipse

    // Create an array of SDL_Points containing perimeter of ellipse 
    // do SDL_RenderDrawPoints(SDL_Points*)

    return true;
}