/** medialayer_sdl_drawing_renderer.h
 *
 * 
 */
#ifndef MEDIALAYER_SDL_DRAWING_RENDERER_H
#define MEDIALAYER_SDL_DRAWING_RENDERER_H

#include <SDL2/SDL.h>
#include "medialayer_drawing_renderer.h"

class MediaLayer_SDL_Drawing_Renderer: public MediaLayer_Drawing_Renderer
{

public:

    MediaLayer_SDL_Drawing_Renderer();

    ~MediaLayer_SDL_Drawing_Renderer();

    bool initialize(SDL_Renderer* renderer, SDL_Window* window);

    // Render Text
    bool render_text(
            std::string text,
            std::string font_src, int font_size,
            int x, int y,
            int r, int g, int b, int alpha) override;

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
            int r, int g, int b, int alpha, 
            bool fill = false) override;

    // Render circle
    bool render_circle(
            int centerX, int centerY, 
            int radius, 
            int r, int g, int b, int alpha, 
            bool fill = false) override;

    // Render ellipse
    bool render_ellipse(
            int aX, int aY, 
            int radiusX, int radiusY, 
            int r, int g, int b, int alpha, 
            bool fill = false) override;

private:

    SDL_Renderer* _renderer;
    SDL_Window* _window;

    // Free Resources
    void free();

};
#endif