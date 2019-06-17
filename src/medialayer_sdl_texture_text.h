/** medialayer_sdl_texture_text.h
 * 
 *  SDL texture wrapper class for rendering 
 */

#ifndef MEDIALAYER_SDL_TEXTURE_TEXT_H
#define MEDIALAYER_SDL_TEXTURE_TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <vector>

#include "medialayer_sdl_texture.h"

class MediaLayer_SDL_Texture_Text: public MediaLayer_SDL_Texture{
 
 public:

    MediaLayer_SDL_Texture_Text();

    ~MediaLayer_SDL_Texture_Text();

    // Deallocates memory
    void free();

    // Set path of the image or ttf font
    void set_font_source_path(std::string path);

    // Set font size
    void set_font_size(int size);

    // Load texture with text
    bool load() override;

    // Creates image from font string, with color
    void load_text(std::string text, int size, SDL_Color color);

private:

    std::string _font_source_path;
    TTF_Font* _font;
    int _font_size;

    std::string _text;
    SDL_Color _color;

};

#endif
 


