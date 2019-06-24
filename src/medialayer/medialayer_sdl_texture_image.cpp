/** medialayer_sdL_texture_image.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include "medialayer_sdl_texture_image.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace MediaLayer{
    namespace SDL{

/** Constructor
 * 
 */
        Texture_Image::Texture_Image():
            Texture()
        {
        }

/** Destructor
 * 
 */
        Texture_Image::~Texture_Image()
        {
            _source_path = "";

            free();
        }

/** function: free()
 * 
 */
        void Texture_Image::free()
        {
            Texture::free();
        }

/** function: set_source_path()
 * 
 */
        void Texture_Image::set_source_path(std::string path)
        { 
            _source_path = path; 
        }

/** function: load()
 * 
 */
        bool Texture_Image::load()
        {
            free();

            if(_source_path == "")
            {
                // No Path Set
                return false;
            }

            // Load image at specified path
            SDL_Surface* loaded_surface{IMG_Load(_source_path.c_str())};

            if(loaded_surface == NULL)
            {
                // failed to load image
                SDL_Log("Unable to load image %s : SDL_image Error: %s",
                        _source_path.c_str(),
                        IMG_GetError());
            } else
            {
                //Color key image
                SDL_SetColorKey(loaded_surface, 
                                SDL_TRUE, 
                                SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));
        
                // Create texture
                _texture = SDL_CreateTextureFromSurface(_renderer, loaded_surface);

                if(_texture == nullptr){
                    SDL_Log("Unable to create texture from %s : SDL Error: %s",
                            _source_path.c_str(),
                            SDL_GetError());
                } else
                {
                    // Get dimensions
                    _width = loaded_surface->w;
                    _height = loaded_surface->h;
                }

                // Get rid of old loaded surface
            }
    
            // Free surface resource 
            SDL_FreeSurface(loaded_surface);

            return _texture != nullptr;
        }

    } // namespace SDL
} // namespace Media
