/** medialayer_sdL_texture_text.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include "medialayer_sdl_texture_text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

namespace MediaLayer{
    namespace SDL{

/** Constructor
 *   @dynamic_text: [placeholder] indicates whether text content will update
 */
        Texture_Text::Texture_Text(bool dynamic_text):
            Texture(),
            _font_size(0),
            _dynamic_text(dynamic_text)
        {
        }

/** Destructor
 */
        Texture_Text::~Texture_Text()
        {
            free();
        }

/** function: free() 
 * Frees resources
 */
        void Texture_Text::free()
        {
            _free_font();

            Texture::free();
        }

/** private function: _free_font()
 * Deallocates font resource
 */
        void Texture_Text::_free_font()
        {
            if(!_font)
            {
		TTF_CloseFont(_font);
		_font = nullptr;
            }
        }

/** private function: _open_font()
 * Opens font resource
 */
        bool Texture_Text::_open_font()
        {
            // Clear any existing font resources
            _free_font();

            // Sanity Check
            if(_font_source_path.empty()){
		// Font source path is empty
		return false;
            } else if(_font_size < 1){
		// Invalid font size
		return false;
            }

            _font = TTF_OpenFont(_font_source_path.c_str(), _font_size);

            return _font != nullptr;	
        }

/** function: set_font
 * Sets font for the text
 *   @source_path: path for the ttf font file
 *   @font_size: font size
 */
        void Texture_Text::set_font(
                std::string source_path, 
                int font_size)
        { 
            _font_source_path = source_path; 
            _font_size = font_size;
        }

/** function: set_font
 * Sets font for the text
 *   @source_path: path for the ttf font file
 *   @font_size: font size
 *   @r, @g, @b, @alpha: font color and transparency
 */
        void Texture_Text::set_font(
                std::string source_path, 
                int size, 
                int r, int g, int b, int alpha)
        { 
            _set_font_color(r, g, b, alpha);
            set_font(source_path, size);
        }

/** private function: set_font_color
 * Sets font color and transparency
 *   @r, @g, @b, @alpha: Color and transparency
 */
        void Texture_Text::_set_font_color(
                int r, int g, int b, int alpha)
        { 
            _color = SDL_Color{
                static_cast<Uint8>(r), 
                static_cast<Uint8>(g), 
                static_cast<Uint8>(b), 
                static_cast<Uint8>(alpha)};
        }

/** function: load_text()
 * Sets text content to be rendered
 *   @text: text content
 */
        void Texture_Text::load_text(
                std::string text)
        {
            _text = text;
        }

/** public function: text()
 * Text content to be rendered
 */
        std::string Texture_Text::text()
        {
            return _text;
        }

/** public function: is_dynamic()
 *  Indicates whether the text is dynamic, i.e., constantly changes
 *  over time.
 */
        bool Texture_Text::is_dynamic()
        {
            return _dynamic_text;
        }

/** public function: load() 
 * Creates texture and loads text to be rendered to screen
 *  @text: text content to be rendered
 *  @font_source_path, @font_size: Font style and size
 *  @r, @g, @b, @alpha: Font color and transparency
 */
        bool Texture_Text::load(
                std::string text,
                std::string font_source_path, 
                int font_size, 
                int r, int g, int b, int alpha)
        {
            set_font(font_source_path, font_size, r, g, b, alpha);
            load_text(text);
            return load();
        }

/** public function load()
 * Creates Texture to be rendered to screen
 */
        bool Texture_Text::load()
        {
            // Free texture
            free();

            _font = TTF_OpenFont(_font_source_path.c_str(), _font_size);	

            if(!_font)
            {
		SDL_Log("Unable to load font %s\n%s",
                        _font_source_path.c_str(),
                        SDL_GetError());
		return false;
            }

            //Render text surface
            SDL_Surface* text_surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);

            if(!text_surface)
            {
		SDL_Log("Unable to render text surface. SDL_ttf Error: %s\n",
                         TTF_GetError() );
            }
            else
            {
		//Create texture from surface pixels
                _texture = SDL_CreateTextureFromSurface(_renderer, text_surface);

		if(!_texture)
		{
                    SDL_Log("Unable to create texture from rendered text. SDL Error: %s\n",
                            SDL_GetError() );
		}
		else
		{
                    //Get image dimensions
                    _width = text_surface->w;
                    _height = text_surface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(text_surface);
            }

            // Free font if static, keep open if text will change
            TTF_CloseFont(_font);

            //Return success
            return _texture != nullptr;
        }

    } // namespace SDL
} // namespace Media
