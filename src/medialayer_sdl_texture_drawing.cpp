/** medialayer_sdL_texture_drawing.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include "medialayer_sdl_texture_drawing.h"
#include "medialayer_sdl_texture.h"

#include <SDL2/SDL.h>
#include <vector>

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

bool MediaLayer_SDL_Texture_Drawing::initialize(SDL_Renderer* renderer, SDL_Window* window, int width, int height)
{
    MediaLayer_SDL_Texture::initialize(renderer, window);
    _width = width;
    _height = height;
    bool ret_val = load();
    return ret_val;
}

/** function: free()
 * 
 */
void MediaLayer_SDL_Texture_Drawing::free()
{
    MediaLayer_SDL_Texture::free();
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
                                 SDL_TEXTUREACCESS_STREAMING, 
                                 _width, 
                                 _height);

    return _texture != nullptr;
}


/** function: set_drawing()
 * 
 */
void MediaLayer_SDL_Texture_Drawing::render(std::vector<Drawing> drawings, int x, int y)
{
    if(_texture == nullptr)
    {
        SDL_Log("Texture is null");
        return;
    }

    // Set Render Target
    SDL_SetRenderTarget(_renderer, _texture);

    // Texture background
    SDL_SetRenderDrawColor(_renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

    // Clear whatever was previously on texture 
    SDL_RenderClear(_renderer);

    // Render all drawings
    for(Drawing drawing: drawings)
    {
        // render_drawing(drawing);
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

    }

    /// Reset Render Target to default window
    SDL_SetRenderTarget(_renderer, nullptr);

    SDL_Rect destrect{x, y, _width / 2, _height / 2}, srcrect{50, 50, _width / 8, _height / 8};
    SDL_RenderCopy(_renderer, _texture, &srcrect, &destrect);
    // MediaLayer_SDL_Texture::render(x, y);
}

/** function: render_point()
 * 
 */
void MediaLayer_SDL_Texture_Drawing::render_drawing(Drawing drawing)
{
    // Render all the points in the drawing 
    for(Drawing::Point point: drawing.drawing())
    {
        render_point(point);
    }
}

/** function: render_point()
 * 
 */
void MediaLayer_SDL_Texture_Drawing::render_point(Drawing::Point point)
{
        // Set Color
        SDL_SetRenderDrawColor(_renderer,
                                point.color.r, 
                                point.color.g, 
                                point.color.b, 
                                point.color.alpha);
        SDL_RenderDrawPoint(_renderer, point.x, point.y); 
}