/** medialayer_drawing_renderer.h
 *
 */
#ifndef MEDIALAYER_DRAWING_RENDERER_H
#define MEDIALAYER_DRAWING_RENDERER_H

#include <string>

namespace MediaLayer{
  
    class Drawing_Renderer
    {

    public:

        Drawing_Renderer(){}

        virtual ~Drawing_Renderer(){}

        // Initialize texture for rendering text, returns index for reference
        virtual int initialize_text(
                std::string text,
                std::string font_src, int font_size,
                int x, int y,
                int r, int g, int b, int alpha)=0;

        // Update text of an existing texture
        virtual bool update_text(
                int texture_index,
                std::string text,
                std::string font_src, int font_size,
                int r, int g, int b, int alpha)=0;

        // Render Text to screen
        virtual bool render_text(
                int texture_index,
                int x, int y)=0;

        // Render point
        virtual bool render_point(
                int x, int y, 
                int r, int g, int b, int alpha)=0;

        // Render line
        virtual bool render_line(
                int aX, int aY, 
                int bX, int bY, 
                int r, int g, int b, int alpha, 
                int thickness =1)=0;

        // Render rectangle
        virtual bool render_rectangle(
                int x1, int y1, 
                int x2, int y2, 
                int r, int g, int b, int alpha)=0;

        // Render rectangle
        virtual bool render_filled_rectangle(
                int x1, int y1, 
                int x2, int y2, 
                int r, int g, int b, int alpha)=0;

        // Render circle
        virtual bool render_circle(
                int centerX, int centerY, 
                int radius, 
                int r, int g, int b, int alpha)=0;

        // Render circle
        virtual bool render_filled_circle(
                int centerX, int centerY, 
                int radius, 
                int r, int g, int b, int alpha)=0;

        // Render ellipse
        virtual bool render_ellipse(
                int aX, int aY, 
                int radiusX, int radiusY, 
                int r, int g, int b, int alpha)=0;

        // Render ellipse
        virtual bool render_filled_ellipse(
                int aX, int aY, 
                int radiusX, int radiusY, 
                int r, int g, int b, int alpha)=0;

        // Render polygon
        virtual bool render_polygon(
                short* vx, short* vy,
                int n,
                int r, int g, int b, int alpha)=0;

        // Render filled polygon
        virtual bool render_filled_polygon(
                short* vx, short* vy,
                int n,
                int r, int g, int b, int alpha)=0;
    };
  
} // namespace Media
#endif
