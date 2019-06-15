/** medialayer_sdl_texture_drawing.h
 * 
 *  SDL texture wrapper class for rendering vector shapes
 */

#ifndef MEDIALAYER_SDL_TEXTURE_DRAWING_H
#define MEDIALAYER_SDL_TEXTURE_DRAWING_H

#include <SDL2/SDL.h>

#include <string>
#include <vector>

#include "medialayer_sdl_texture.h"

#include "drawing.h"

class MediaLayer_SDL_Texture_Drawing: public MediaLayer_SDL_Texture{

public:

    MediaLayer_SDL_Texture_Drawing();

    // Deallocates memory
    ~MediaLayer_SDL_Texture_Drawing();

    void free();

    bool load() override;

    // Creates vector graphics from collection of points
    void render_drawing(Drawing drawing);

private:

};

#endif
 

