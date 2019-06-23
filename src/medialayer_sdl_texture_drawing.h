/** medialayer_sdl_texture_drawing_element.h
 * 
 *  SDL texture wrapper class for rendering vector shapes
 */

#ifndef MEDIALAYER_SDL_TEXTURE_DRAWING_H
#define MEDIALAYER_SDL_TEXTURE_DRAWING_H

#include <SDL2/SDL.h>
#include <vector>

#include "medialayer_sdl_texture.h"
#include "drawing_element.h"

namespace SDL{

class Texture_Drawing: public Texture{

public:

    Texture_Drawing();

    // Deallocates memory
    ~Texture_Drawing();

    bool initialize(SDL_Renderer* renderer, SDL_Window* window, int width, int height);

    void free();

    bool load() override;

    // Renders collection of Drawing objects to texture
//    void render(std::vector<Drawing> drawings, int x, int y);

private:

//    // Render individual drawing to texture
//    void render_drawing(Drawing drawing);

//    // Renders individual point to texture
//    void render_point(DrawingElement::Position point);

};

} // namespace SDL
#endif
