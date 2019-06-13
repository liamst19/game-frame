/** medialayer_sdL_texture_image.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <vector>

#include "medialayer_sdl_texture_image.h"
#include "math.h"

/** Constructor
 * 
 */
MediaLayer_SDL_Texture_Image::MediaLayer_SDL_Texture_Image(SDL_Renderer* renderer, SDL_Window* window):
    MediaLayer_SDL_Texture(renderer, window)
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture_Image::~MediaLayer_SDL_Texture_Image()
{
    _source_path = "";

    free();
}

void MediaLayer_SDL_Texture_Image::free(){

    MediaLayer_SDL_Texture::free();

}

bool MediaLayer_SDL_Texture_Image::load(){
    free();

    if(_source_path == ""){
        // No Path Set
        return false;
    }

    // The final texture
    SDL_Texture* new_texture{NULL};

    // Load image at specified path
    SDL_Surface* loaded_surface{IMG_Load(_source_path.c_str())};

    if(loaded_surface == NULL){
        // failed to load image
        SDL_Log("Unable to load image %s : SDL_image Error: %s", _source_path.c_str(), IMG_GetError());
    } else{
        //Color key image
        SDL_SetColorKey(loaded_surface, 
                        SDL_TRUE, 
                        SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));
        
        // Create texture
        new_texture = SDL_CreateTextureFromSurface(_renderer, loaded_surface);
        if(new_texture == NULL){
            SDL_Log("Unable to create texture from %s : SDL Error: %s", _source_path.c_str(), SDL_GetError());
        } else{
            // Get dimensions
            _width = loaded_surface->w;
            _height = loaded_surface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loaded_surface);
    }

    //Return
    _texture = new_texture;
    return _texture != NULL;
}

