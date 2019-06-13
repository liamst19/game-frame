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

    MediaLayer_SDL_Texture_Text(SDL_Renderer* renderer, SDL_Window* window);

    // Deallocates memory
    ~MediaLayer_SDL_Texture_Text();

    void free();

    // Set path of the image or ttf font
    void set_source_path(std::string path){ _source_path = path; }

    // Set font size
    void set_font_size(int size){ _font_size = size; }

    bool load() override;

    // Creates image from font string, with color
    void load_text(std::string text, SDL_Color color);

private:

    std::string _source_path;
    TTF_Font* _font;
    int _font_size;

    std::string _text;
    SDL_Color _color;

};

#endif
 


