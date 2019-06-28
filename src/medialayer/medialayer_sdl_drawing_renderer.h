/** medialayer_sdl_drawing_renderer.h
 *
 * 
 */
#ifndef MEDIALAYER_SDL_DRAWING_RENDERER_H
#define MEDIALAYER_SDL_DRAWING_RENDERER_H

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "medialayer_drawing_renderer.h"
#include "medialayer_sdl_texture.h"

namespace MediaLayer{
    namespace SDL{

        class SDL_Drawing_Renderer: public Drawing_Renderer
        {

        public:

            SDL_Drawing_Renderer();

            ~SDL_Drawing_Renderer();

            bool initialize(SDL_Renderer* renderer, SDL_Window* window);

// ------------------------------------------------------------
            // Get Texture Width
            int texture_width(int texture_index);

            // Get Texture Height
            int texture_height(int texture_index);
// ------------------------------------------------------------
// Text
            // Initialize texture for rendering text
            int initialize_text(
                    std::string text,
                    std::string font_src, int font_size,
                    int x, int y,
                    int r, int g, int b, int alpha) override;

            // Update text of an existing texture
            bool update_text(
                    int texture_index,
                    std::string text,
                    std::string font_src, int font_size,
                    int r, int g, int b, int alpha) override;

            // Render Text to screen
            bool render_text(
                    int texture_index,
                    int x, int y) override;
            
// ------------------------------------------------------------
// Image

            // Initialize texture for image
            int initialize_image(
                    std::string source_path) override;

            // Render Image to screen
            bool render_image(
                    int texture_index,
                    int x, int y) override;
            
// ------------------------------------------------------------
            
            // Render point
            bool render_point(
                    int x, int y, 
                    int r, int g, int b, int alpha) override;

            // Render line
            bool render_line(
                    int aX, int aY, 
                    int bX, int bY, 
                    int r, int g, int b, int alpha, 
                    int thickness = 1) override;

            // Render rectangle
            bool render_rectangle(
                    int x1, int y1, 
                    int x2, int y2, 
                    int r, int g, int b, int alpha) override;

            // Render rectangle
            bool render_filled_rectangle(
                    int x1, int y1, 
                    int x2, int y2, 
                    int r, int g, int b, int alpha) override;

            // Render circle
            bool render_circle(
                    int centerX, int centerY, 
                    int radius, 
                    int r, int g, int b, int alpha) override;

            // Render circle
            bool render_filled_circle(
                    int centerX, int centerY, 
                    int radius, 
                    int r, int g, int b, int alpha) override;

            // Render ellipse
            bool render_ellipse(
                    int aX, int aY, 
                    int radiusX, int radiusY, 
                    int r, int g, int b, int alpha) override;

            // Render ellipse
            bool render_filled_ellipse(
                    int aX, int aY, 
                    int radiusX, int radiusY, 
                    int r, int g, int b, int alpha) override;

            // Render polygon
            bool render_polygon(
                    short* vx, short* vy,
                    int n,
                    int r, int g, int b, int alpha) override;

            // Render filled polygon
            bool render_filled_polygon(
                    short* vx, short* vy,
                    int n,
                    int r, int g, int b, int alpha) override;

        private:

            SDL_Renderer* _renderer;
            SDL_Window* _window;

            std::vector<std::unique_ptr<Texture>> _textures;

            // Free Resources
            void _free();

            // Adds texture to collection, returns index
            int _add_texture(std::unique_ptr<Texture> texture);

            // Render Texture
            bool _render_texture(
                    int texture_index,
                    int x, int y);

        };

    } // namespace SDL
} // namespace Media
#endif
