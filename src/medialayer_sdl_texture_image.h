/** medialayer_sdl_texture_image.h
 * 
 *  SDL texture wrapper class for rendering images
 */

#ifndef MEDIALAYER_SDL_TEXTURE_IMAGE_H
#define MEDIALAYER_SDL_TEXTURE_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <vector>

#include "medialayer_sdl_texture.h"

class MediaLayer_SDL_Texture_Image: public MediaLayer_SDL_Texture{

public:

    MediaLayer_SDL_Texture_Image(SDL_Renderer* renderer, SDL_Window* window);

    // Deallocates memory
    ~MediaLayer_SDL_Texture_Image();

    void free();

    // Set path of the image or ttf font
    void set_source_path(std::string path){ _source_path = path; }

    bool load() override;

    // Loads image from specific path
    void load_image(std::string path);

private:

    std::string _source_path;

};

#endif
 


