/** medialayer_sdL_texture.cpp
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

#include "medialayer_sdl_texture.h"

/** Constructor
 * 
 */
MediaLayer_SDL_Texture::MediaLayer_SDL_Texture():
    _renderer{nullptr},
    _window{nullptr},
    _texture{nullptr},
    _width{0},
    _height{0}
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture::~MediaLayer_SDL_Texture()
{
    // Deallocate
    free();
}

bool MediaLayer_SDL_Texture::initialize(SDL_Renderer* renderer, SDL_Window* window)
{
    _renderer = renderer;
    _window = window;
    return true;
}

/** function: free()
 * 
 */
void MediaLayer_SDL_Texture::free()
{
    // Free texture
    if(_texture != nullptr){
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
        _width = 0;
        _height = 0;
    }
}

/** function: set_renderer()
 * 
 */
void MediaLayer_SDL_Texture::set_renderer(SDL_Renderer* renderer)
{
    _renderer = renderer;
}

/** function: render()
 * 
 */
void MediaLayer_SDL_Texture::render(int x, 
                                    int y, 
                                    double angle, 
                                    SDL_Rect* clip, 
                                    SDL_Point* center, 
                                    SDL_RendererFlip flip)
{
    int result = 0;
    
    if(!_texture)
    {
        SDL_Log("No texture");
        return;
    }

    // Set rendering space
    SDL_Rect render_quad{x, y, _width, _height};

    // Set clip rendering dimensions
    if(clip != nullptr){
        render_quad.w = clip->w;
        render_quad.h = clip->h;
    }

    //Render
    result = SDL_RenderCopyEx(_renderer, 
                              _texture, 
                              clip, 
                              &render_quad, 
                              angle, 
                              center, 
                              flip);
    if(result != 0){
        SDL_Log("%s", SDL_GetError());
    }
}

/** function: width()
 * 
 */
int MediaLayer_SDL_Texture::width()
{
    return _width;
}

/** function: height()
 * 
 */
int MediaLayer_SDL_Texture::height()
{
    return _height;
}

/** function: set_color()
 * Modulate texture RGB
 */
void MediaLayer_SDL_Texture::set_color(Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetTextureColorMod(_texture, red, green, blue);
}

/** function: set_blending()
 * Set blending function
 */
void MediaLayer_SDL_Texture::set_blending(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(_texture, blending);
}

/** function: set_alpha()
 *  Modulate texture alpha 
 */
void MediaLayer_SDL_Texture::set_alpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(_texture, alpha);
}
