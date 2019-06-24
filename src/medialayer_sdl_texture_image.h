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


namespace MediaLayer{
namespace SDL{

class Texture_Image: public Texture{

public:

    Texture_Image();

    // Deallocates memory
    ~Texture_Image();

    void free();

    // Set path of the image or ttf font
    void set_source_path(std::string path);

    bool load() override;

private:

    std::string _source_path;
};

} // namespace SDL
} // namespace Media
#endif
