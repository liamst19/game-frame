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

/** Constructor
 * 
 */
MediaLayer_SDL_Texture_Text::MediaLayer_SDL_Texture_Text(bool dynamic_text):
    MediaLayer_SDL_Texture(),
    _font_size(0),
	_dynamic_text(dynamic_text)
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture_Text::~MediaLayer_SDL_Texture_Text()
{
	free();
}

/** function: free() 
 * 
 */
void MediaLayer_SDL_Texture_Text::free()
{
	_free_font();

	MediaLayer_SDL_Texture::free();
}

/** private function: _free_font()
 *  Deallocates font resource
 */
void MediaLayer_SDL_Texture_Text::_free_font()
{
	if(!_font)
	{
		TTF_CloseFont(_font);
		_font = nullptr;
	}
}

/** private function: _open_font()
 * 	Opens font resource
 */
bool MediaLayer_SDL_Texture_Text::_open_font()
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

/** function: set_font_source_path
 * 
 */
void MediaLayer_SDL_Texture_Text::set_font(
			std::string source_path, 
			int size)
{ 
	_font_source_path = source_path; 
	_font_size = size;
}

/** function: set_font_source_path
 * 
 */
void MediaLayer_SDL_Texture_Text::set_font(
			std::string source_path, 
			int size, 
			int r, int g, int b, int alpha)
{ 
	_set_font_color(r, g, b, alpha);
	set_font(source_path, size);
}

/** private function: set_font_color
 * 
 */
void MediaLayer_SDL_Texture_Text::_set_font_color(
			int r, int g, int b, int alpha)
{ 
	_color = SDL_Color{
				static_cast<Uint8>(r), 
				static_cast<Uint8>(g), 
				static_cast<Uint8>(b), 
				static_cast<Uint8>(alpha)};
}

/** function: load_text()
 * 
 */
void MediaLayer_SDL_Texture_Text::load_text(
			std::string text)
{
	_text = text;
}

/** public function: text()
 * 
 */
std::string MediaLayer_SDL_Texture_Text::text()
{
	return _text;
}

/** public function: is_dynamic()
 *  Indicates whether the text is dynamic, i.e., constantly changes over time.
 */
bool MediaLayer_SDL_Texture_Text::is_dynamic()
{
	return _dynamic_text;
}

/** public function: load() 
 * 
 */
bool MediaLayer_SDL_Texture_Text::load(
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
 * 
 */
bool MediaLayer_SDL_Texture_Text::load()
{
	// Free texture
	free();

	_font = TTF_OpenFont(_font_source_path.c_str(), _font_size);	

	if(!_font)
	{
		SDL_Log("Unable to load font %s\n%s", _font_source_path.c_str(), SDL_GetError());
		return false;
	}

	//Render text surface
	SDL_Surface* text_surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);

	if(!text_surface)
	{
		SDL_Log( "Unable to render text surface. SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        _texture = SDL_CreateTextureFromSurface(_renderer, text_surface);

		if(!_texture)
		{
			SDL_Log( "Unable to create texture from rendered text. SDL Error: %s\n", SDL_GetError() );
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