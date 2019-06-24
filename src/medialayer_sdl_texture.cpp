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

namespace MediaLayer{
namespace SDL{

/** Constructor
 * 
 */
  Texture::Texture():
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
Texture::~Texture()
{
    // Deallocate
    free();
}

/** public function: initialize()
 * Sets SDL renderer and window 
 *   @renderer: SDL renderer
 *   @window: window context
 */
bool Texture::initialize(SDL_Renderer* renderer, SDL_Window* window)
{
    _renderer = renderer;
    _window = window;
    return true;
}

/** function: free()
 * Frees resources
 */
void Texture::free()
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
 * Set SDL renderer for the texture
 *   @renderer: SDL renderer
 */
void Texture::set_renderer(SDL_Renderer* renderer)
{
    _renderer = renderer;
}

/** function: render()
 * Render texture to screen
 *   @x, @y: Position for rendering texture
 *   @angle: Rotation of texture
 *   @clip: 
 *   @center:
 *   @flip: 
 */
void Texture::render(int x, 
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
 * Texture width
 */
int Texture::width()
{
    return _width;
}

/** function: height()
 * Texture height
 */
int Texture::height()
{
    return _height;
}

/** function: set_color()
 * Modulate texture RGB
 *   @red, @green, @blue: Colors
 */
void Texture::set_color(Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetTextureColorMod(_texture, red, green, blue);
}

/** function: set_blending()
 * Set blending function
 */
void Texture::set_blending(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(_texture, blending);
}

/** function: set_alpha()
 *  Modulate texture alpha 
 */
void Texture::set_alpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(_texture, alpha);
}

} // namespace SDL

} // namespace Media
