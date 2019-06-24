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

// #include "drawing_element.h"     

namespace MediaLayer{
    namespace SDL{

/** Constructor
 * 
 */
        Texture_Drawing::Texture_Drawing():
            Texture()
        {
        }

/** Destructor
 * 
 */
        Texture_Drawing::~Texture_Drawing()
        {
            free();
        }

        bool Texture_Drawing::initialize(
                SDL_Renderer* renderer,
                SDL_Window* window,
                int width, int height)
        {
            Texture::initialize(renderer, window);
            _width = width;
            _height = height;
            bool ret_val = load();
            return ret_val;
        }

/** function: free()
 * 
 */
        void Texture_Drawing::free()
        {
            Texture::free();
        }

/** function: load()
 * 
 */
        bool Texture_Drawing::load()
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

// /** function: render()
//  * 
//  */
// void Texture_Drawing::render(std::vector<Drawing> drawings, int x, int y)
// {
//     if(_texture == nullptr)
//     {
//         SDL_Log("Texture is null");
//         return;
//     }

//     // Set Render Target
//     SDL_SetRenderTarget(_renderer, _texture);

//     // Texture background
//     SDL_SetRenderDrawColor(_renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

//     // Clear whatever was previously on texture 
//     SDL_RenderClear(_renderer);

//    // Render all drawings
//    for(Drawing drawing: drawings)
//    {
//        // render_drawing(drawing);
//        // Render all the points in the drawing

//        for(DrawingElement::Position point: drawing.drawing())
//        {
//            // Set Color
//            SDL_SetRenderDrawColor(_renderer,
//                                    point.color.r, 
//                                    point.color.g, 
//                                    point.color.b, 
//                                    point.color.alpha);
//            SDL_RenderDrawPoint(_renderer, point.x, point.y); 
//        }

//    }

//    /// Reset Render Target to default window
//    SDL_SetRenderTarget(_renderer, nullptr);

//    SDL_Rect destrect{x, y, _width / 2, _height / 2}, srcrect{50, 50, _width / 8, _height / 8};
//    SDL_RenderCopy(_renderer, _texture, &srcrect, &destrect);
//    // Texture::render(x, y);
//}

// /** function: render_point()
//  * 
//  */
// void Texture_Drawing::render_drawing(Drawing drawing)
// {
//     // Render all the points in the drawing 
//     for(DrawingElement::Position point: drawing.drawing())
//     {
//         render_point(point);
//     }
// }

// /** function: render_point()
//  * 
//  */
// void Texture_Drawing::render_point(DrawingElement::Position point)
// {
//         // Set Color
//         SDL_SetRenderDrawColor(_renderer,
//                                 point.color.r, 
//                                 point.color.g, 
//                                 point.color.b, 
//                                 point.color.alpha);
//         SDL_RenderDrawPoint(_renderer, point.x, point.y); 
// }

    } // namespace SDL
} // namespace Media
