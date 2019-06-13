/** medialayer_sdL_texture_text.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <vector>

#include "medialayer_sdl_texture_text.h"

/** Constructor
 * 
 */
MediaLayer_SDL_Texture_Text::MediaLayer_SDL_Texture_Text(SDL_Renderer* renderer, SDL_Window* window):
    MediaLayer_SDL_Texture(renderer, window),
    _font_size(0)
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture_Text::~MediaLayer_SDL_Texture_Text()
{
	free();
}

void MediaLayer_SDL_Texture_Text::free(){
	MediaLayer_SDL_Texture::free();

    if(_font != nullptr){
        _font = nullptr;
        _font_size = 0;
    }
}

/** function: load_text()
 * 
 */
void MediaLayer_SDL_Texture_Text::load_text(std::string text, SDL_Color color){
	_text = text;
	_color = color;
}

bool MediaLayer_SDL_Texture_Text::load(){

	//Get rid of preexisting texture
	free();

    _font = TTF_OpenFont(_font_source_path.c_str(), _font_size);

    if(_font == nullptr){
        SDL_Log("Unable to load font");
        return false;
    }

	//Render text surface
	SDL_Surface* text_surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);

	if(text_surface == nullptr)
	{
		SDL_Log( "Unable to render text surface. SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        _texture = SDL_CreateTextureFromSurface(_renderer, text_surface);

		if(_texture == nullptr)
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

    TTF_CloseFont(_font);	

	//Return success
	return _texture != NULL;
}