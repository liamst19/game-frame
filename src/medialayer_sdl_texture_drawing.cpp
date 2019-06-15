/** medialayer_sdL_texture_drawing.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include <SDL2/SDL.h>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "medialayer_sdl_texture_drawing.h"
#include "math_vector_2d.h"
#include "drawing.h"

/** Constructor
 * 
 */
MediaLayer_SDL_Texture_Drawing::MediaLayer_SDL_Texture_Drawing():
    MediaLayer_SDL_Texture()
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture_Drawing::~MediaLayer_SDL_Texture_Drawing()
{
    free();
}

/** function: free()
 * 
 */
void MediaLayer_SDL_Texture_Drawing::free()
{
    MediaLayer_SDL_Texture::free();
}

/** function: set_drawing()
 * 
 */
void MediaLayer_SDL_Texture_Drawing::render_drawing(Drawing drawing)
{ 
    // Set Render Target
    int i = SDL_SetRenderTarget(_renderer, _texture);

    // Texture background
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

    // Clear whatever was previously on texture 
    SDL_RenderClear(_renderer);

    // Render all the points in the drawing 
    for(Drawing::Point point: drawing.drawing())
    {
        // Set Color
        SDL_SetRenderDrawColor(_renderer,
                                point.color.r, 
                                point.color.g, 
                                point.color.b, 
                                point.color.alpha);
        SDL_RenderDrawPoint(_renderer, point.x, point.y); 
    }

    // Draw onto texture
    SDL_RenderPresent(_renderer);

    /// Reset Render Target to default window
    SDL_SetRenderTarget(_renderer, NULL);
}

/** function: load()
 * 
 */
bool MediaLayer_SDL_Texture_Drawing::load()
{
    free();

    // The final texture
    _texture = SDL_CreateTexture(_renderer, 
                                 SDL_GetWindowPixelFormat(_window), 
                                 SDL_TEXTUREACCESS_TARGET, 
                                 _width, 
                                 _height);

    return true;
}