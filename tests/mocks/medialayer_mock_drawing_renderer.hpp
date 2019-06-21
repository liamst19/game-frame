/** medialayer_mock_drawing_renderer.hpp
 * Mock MediaLayer Object
 */

#ifndef MEDIALAYER_MOCK_DRAWING_RENDERER_H
#define MEDIALAYER_MOCK_DRAWING_RENDERER_H

#include <vector>
#include "../../src/medialayer.h"


class MediaLayer_Mock_Drawing_Renderer: public MediaLayer_Drawing_Renderer
{
public:

    MediaLayer_Mock_Drawing_Renderer(){}

    virtual ~MediaLayer_Mock_Drawing_Renderer(){}

    // Render Text
    bool render_text(
            std::string text,
            std::string font_src, int font_size,
            int x, int y,
            int r, int g, int b, int alpha)
    {
        return true;
    }

    // Render point
    virtual bool render_point(int x, int y, int r, int g, int b, int alpha)
    {
        return true;
    }

    // Render line
    virtual bool render_line(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, int thickness =1)
    {
        return true; 
    }

    // Render rectangle outline
    virtual bool render_rectangle(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill = false)
    {
        return true; 
    }

    // Render circle
    virtual bool render_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha, bool fill = false)
    {
        return true; 
    }

    // Render ellipse
    virtual bool render_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha, bool fill = false)
    {
        return true; 
    }

};
#endif