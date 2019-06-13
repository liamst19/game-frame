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

#include "medialayer_sdl_texture_drawing.h"
#include "math.h"
#include "drawing.h"
#include "drawing_element.h"

/** Constructor
 * 
 */
MediaLayer_SDL_Texture_Drawing::MediaLayer_SDL_Texture_Drawing(SDL_Renderer* renderer, SDL_Window* window):
    MediaLayer_SDL_Texture(renderer, window)
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture_Drawing::~MediaLayer_SDL_Texture_Drawing()
{
    free();
}

void MediaLayer_SDL_Texture_Drawing::free(){
    MediaLayer_SDL_Texture::free();
}

bool MediaLayer_SDL_Texture_Drawing::load(){
    free();

    if(_drawing.elements().empty()){
        // Drawing is empty
        return false;
    }

    // The final texture
    _texture = SDL_CreateTexture(_renderer, 
                                 SDL_GetWindowPixelFormat(_window), 
                                 SDL_TEXTUREACCESS_TARGET, 
                                 _width, 
                                 _height);
    // Set Render Target
    int i = SDL_SetRenderTarget(_renderer, _texture);

    // Render all the points in the drawing 
    for(DrawingElement element: _drawing.elements()){
        // Set Color
        SDL_SetRenderDrawColor(_renderer,
                               element.color_red(), 
                               element.color_green(), 
                               element.color_blue(), 
                               element.color_alpha());
        // Render Points
        for(Vector2d point: element.draw()){
               SDL_RenderDrawPoint(_renderer, point.x, point.y); 
        }
    }

    // Draw onto texture
    SDL_RenderPresent(_renderer);

    /// Reset Render Target to default window
    SDL_SetRenderTarget(_renderer, NULL);

    return true;
}