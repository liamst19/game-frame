/** medialayer_sdl_drawing_renderer.cpp
 * 
 *  Collection of functions that render various drawings
 *  Using the SDL library. A pointer to this is attached to the Drawing object
 *  upon its creation, so that they can be rendered by simply calling
 *  render() method.
 * 
 *  SDL2_gfx library is used.
 *  
 *  [SDL2_gfx - Graphics primitives and surface functions for SDL2]
 * 
 * 	  	http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/index.html
 * 
 *   Reference for SDL2_gfxPrimitives
 * 		http://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/_s_d_l2__gfx_primitives_8h.html
 * 
 */

#include "medialayer_sdl_drawing_renderer.h"
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "../../include/SDL2/SDL2_gfxPrimitives.h"

#include "medialayer_sdl_texture_text.h"

namespace MediaLayer{
    namespace SDL{

        /** Constructor
         */
        SDL_Drawing_Renderer::SDL_Drawing_Renderer()
        {
        }

        /** Destructor
         */
        SDL_Drawing_Renderer::~SDL_Drawing_Renderer()
        {
            _free(); // Free resources, if any
        }

        /** public function: initialize()
         * Assigns SDL_Renderer and SDL_Window for rendering.
         *   @renderer: The rendering object used to output images to screen
         *   @window: Pointer to application window
         */
        bool SDL_Drawing_Renderer::initialize(SDL_Renderer* renderer, SDL_Window* window)
        {
            _renderer = renderer;
            _window = window;
            return true;
        }

        /** private function: free()
         * Frees resources.
         */
        void SDL_Drawing_Renderer::_free()
        {
            _renderer = nullptr;
            _window = nullptr;
        }

        /** private function: _add_texture()
         * Adds SDL Texture to vector, returns index for reference
         */
        int SDL_Drawing_Renderer::_add_texture(std::unique_ptr<Texture> texture) 
        {
            _textures.emplace_back(std::move(texture));
            int texture_index = _textures.size() - 1;
            return texture_index;
        }

        /** public function: render_text
         * Renders text to screen.
         *   @text: text to be printed
         *   @font_src: font source file
         *   @font_size: font size
         *   @x, @y, position of the text
         *   @color: font color
         */
        int SDL_Drawing_Renderer::initialize_text(std::string text,
                                                  std::string font_src, int font_size,
                                                  int x, int y,
                                                  int r, int g, int b, int alpha)
        {
            int index = -1;

            // Create unique-pointer for adding to vector
            auto texture = std::make_unique<Texture_Text>();

            if(texture->initialize(_renderer, _window))
            {
                // Initialize texture
                texture->load(text, font_src, font_size, r, g, b, alpha);

                // Add to vector, get index
                index = _add_texture(std::move(texture));
            }
            else
            {
                // Initialize failed
                return false;
            }

            return index;
        }

        /** public function: render_text
         * Renders text to screen.
         *   @texture_index: index from collection of textures
         *   @text: text to be printed
         *   @font_src: font source file
         *   @font_size: font size
         *   @r, @g, @b, @alpha: Color and transparency
         */
        bool SDL_Drawing_Renderer::update_text(int texture_index,
                                               std::string text,
                                               std::string font_src, int font_size,
                                               int r, int g, int b, int alpha)
        {
            if(texture_index > 0 && texture_index <= _textures.size())
            {
                return static_cast<Texture_Text*>(_textures[texture_index].get())
                    ->load(text, 
                           font_src, font_size, 
                           r, g, b, alpha);
            }
            else
            {
                // Index is out of range.
                return false;
            }
        }

        /** public function: render_text
         * Renders text to screen.
         *   @text_index: index from collection of textures
         *   @x, @y, position of the text
         */
        bool SDL_Drawing_Renderer::render_text(int texture_index,
                                               int x, int y)
        {
            if(texture_index >= 0 && texture_index <= _textures.size())
            {
                _textures[texture_index].get()->render(x, y);
                return true;
            }
            else
            {
                // Index is out of range.
                return false;
            }
        }

        /** public function: render_point()
         * Renders single pixel to screen.
         *   @x, @y: Coordinates on the screen to be changed.
         *   @r, @g, @b, @alpha: Color and transparency.
         */
        bool SDL_Drawing_Renderer::render_point(int x, int y, 
                                                int r, int g, int b, int alpha)
        {
            return pixelRGBA(_renderer, x, y, r, g, b, alpha) == 0;
        }

        /** public function: render_line()
         * Renders line from point a to b.
         *   @aX, @aY, @bX, @bY: Coordinates of the endpoints
         *   @r, @g, @b, @alpha: Color and transparency values
         *   @thickness: Line thickness [To be implemented]
         */
        bool SDL_Drawing_Renderer::render_line(int aX, int aY, 
                                               int bX, int bY, 
                                               int r, int g, int b, int alpha, 
                                               int thickness)
        {
            int result = 0;
            if(thickness > 1)
            {
                result |= thickLineRGBA(_renderer, aX, aY, bX, bY, thickness, r, g, b, alpha);
            }
            else
            {
                result |= lineRGBA(_renderer, aX, aY, bX, bY, r, g, b, alpha);
            }
            return result == 0;
        }

        /** public function: render_rectangle()
         * Renders rectangle.
         *   @x1, @y1, @x2, @y2: Coordinates of the rectangle to be rendered.
         *   @r, @g, @b, @alpha: Color in RGB and transparency
         */
        bool SDL_Drawing_Renderer::render_rectangle(int x1, int y1, 
                                                    int x2, int y2, 
                                                    int r, int g, int b, int alpha)
        {
            return rectangleRGBA(_renderer, x1, y1, x2, y2, r, g, b, alpha);
        }

        /** public function: render_filled_rectangle()
         * Renders filled rectangle.
         *   @x1, @y1, @x2, @y2: Coordinates of the rectangle to be rendered.
         *   @r, @g, @b, @alpha: Color in RGB and transparency
         */
        bool SDL_Drawing_Renderer::render_filled_rectangle(int x1, int y1, 
                                                           int x2, int y2, 
                                                           int r, int g, int b, int alpha)
        {
            return boxRGBA(_renderer, x1, y1, x2, y2, r, g, b, alpha);
        }

        /** public function: render_circle()
         * Renders circle.
         *   @x, @y: Coordinates of the center
         *   @radius: Radius of circle
         *   @r, @g, @b, alpha: Color and transparency
         */
        bool SDL_Drawing_Renderer::render_circle(int centerX, int centerY, 
                                                 int radius, 
                                                 int r, int g, int b, int alpha)
        {
            return circleRGBA(_renderer, centerX, centerY, radius, r, g, b, alpha);
        }

        /** public function: render_filled_ellipse()
         * Renders filled circle.
         *   @x, @y: Coordinates of the center
         *   @radius: Radius of circle
         *   @r, @g, @b, alpha: Color and transparency
         */
        bool SDL_Drawing_Renderer::render_filled_circle(int centerX, int centerY,
                                                        int radius,
                                                        int r, int g, int b, int alpha)
        {
            return filledCircleRGBA(_renderer, centerX, centerY, radius, r, g, b, alpha);
        }

        /** public function: render_ellipse()
         * Renders ellipse.
         *   @x, @y: Coordinates of the center
         *   @radiusX, radiusY: Horizontal and vertical radii, respectively
         *   @r, @g, @b, alpha: Color and transparency
         */
        bool SDL_Drawing_Renderer::render_ellipse(int x, int y,
                                                  int radiusX, int radiusY, 
                                                  int r, int g, int b, int alpha)
        {
            return ellipseRGBA(_renderer, x, y, radiusX, radiusY, r, g, b, alpha);
        }    

        /** public function: render_filled_ellipse()
         * Renders filled ellipse.
         *   @x, @y: Coordinates of the center
         *   @radiusX, radiusY: Horizontal and vertical radii, respectively
         *   @r, @g, @b, alpha: Color and transparency
         */
        bool SDL_Drawing_Renderer::render_filled_ellipse(int x, int y,
                                                         int radiusX, int radiusY, 
                                                         int r, int g, int b, int alpha)
        {
            return filledEllipseRGBA(_renderer, x, y, radiusX, radiusY, r, g, b, alpha);
        }    

    } // namespace SDL

} // namespace Media
