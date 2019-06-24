/** medialayer_sdl_texture.h
 * 
 *  SDL texture wrapper class for rendering images and text texture
 */

#ifndef MEDIALAYER_SDL_TEXTURE_H 
#define MEDIALAYER_SDL_TEXTURE_H 

#include <SDL2/SDL.h>

#include <string>
#include <vector>

namespace MediaLayer{
    namespace SDL{

        class Texture{

        public:

            Texture();

            // Deallocates memory
            ~Texture();

            bool initialize(SDL_Renderer* renderer, SDL_Window* window);

            // Deallocates texture
            void free();

            // Set SDL_Renderer
            void set_renderer(SDL_Renderer* renderer);

            // Set color modulation
            void set_color(Uint8 red, Uint8 green, Uint8 blue);

            // Set blending
            void set_blending(SDL_BlendMode blending);

            // Set alpha modulation
            void set_alpha(Uint8 alpha);

            // Renders texture at given point
            void render(int x, 
                        int y, 
                        double angle = 0.0, 
                        SDL_Rect* clip = nullptr, 
                        SDL_Point* center = nullptr, 
                        SDL_RendererFlip flip = SDL_FLIP_NONE);
    
            // Gets image width
            int width();

            // Gets image height
            int height();

            // Load Texture
            virtual bool load()=0;

        protected:

            SDL_Window* _window;
            SDL_Renderer* _renderer;

            // SDL texture
            SDL_Texture* _texture;

            // Dimensions
            int _width, _height;

        };

    } // namespace SDL
} // namespace Media
#endif
