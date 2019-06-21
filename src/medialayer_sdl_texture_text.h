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

    MediaLayer_SDL_Texture_Text(bool dynamic_text = false);

    ~MediaLayer_SDL_Texture_Text();

    // Deallocates memory
    void free();


    // Set path of the image or ttf font
    void set_font(
            std::string source_path, 
            int size, 
            int r, int g, int b, int alpha);

    void set_font(
            std::string source_path, int size);

    // Load texture with text
    bool load() override;

    // Load texture with text
    bool load(
            std::string text, 
            std::string font_source_path, 
            int font_size, 
            int r, int g, int b, int alpha);

    // Indicates whether text will update
    bool is_dynamic();

    // Creates image from font string, with color
    void load_text(std::string text);

    std::string text();

private:

    std::string _font_source_path;
    TTF_Font* _font;
    int _font_size;
    bool _dynamic_text;

    std::string _text;
    SDL_Color _color;

    // Open TTF_Font resource
    bool _open_font();

    // Free TTF_Font memory
    void _free_font();

    // Set font color
    void _set_font_color(int r, int g, int b, int alpha);
};

#endif
 


