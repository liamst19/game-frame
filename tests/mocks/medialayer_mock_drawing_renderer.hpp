/** medialayer_mock_drawing_renderer.hpp
 * Mock MediaLayer Object
 */

#ifndef MEDIALAYER_MOCK_DRAWING_RENDERER_H
#define MEDIALAYER_MOCK_DRAWING_RENDERER_H

#include <vector>
#include "../../src/medialayer/medialayer.h"

namespace MediaLayer{

    class Mock_Drawing_Renderer: public Drawing_Renderer
    {
    public:

        Mock_Drawing_Renderer(){}

        virtual ~Mock_Drawing_Renderer(){}

        // Initialize texture for rendering text, returns index for reference
        int initialize_text(
                std::string text,
                std::string font_src, int font_size,
                int x, int y,
                int r, int g, int b, int alpha)
            {
                return 0;
            }

        // Update text of an existing texture
        bool update_text(
                int texture_index,
                std::string text,
                std::string font_src, int font_size,
                int r, int g, int b, int alpha)
            {
                return true;
            }

        // Render Text to screen
        bool render_text(
                int texture_index,
                int x, int y)
            {
                return true;
            }

        // Initialize texture for rendering image
        virtual int initialzie_image(
                std::string source_path)
            {
                return true
                    }

        // Render Image to screen
        virtual bool render_image(
                int texture_index,
                int x, int y)
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
        virtual bool render_rectangle(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha)
            {
                return true; 
            }

        // Render circle
        virtual bool render_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha)
            {
                return true; 
            }

        // Render ellipse
        virtual bool render_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha)
            {
                return true; 
            }

        // Render rectangle outline
        virtual bool render_filled_rectangle(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha)
            {
                return true; 
            }

        // Render circle
        virtual bool render_filled_circle(int centerX, int centerY, int radius, int r, int g, int b, int alpha)
            {
                return true; 
            }

        // Render ellipse
        virtual bool render_filled_ellipse(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha)
            {
                return true; 
            }

        // Render polygon
        bool render_polygon(
                short* vx, short* vy,
                int n,
                int r, int g, int b, int alpha) override
            {
                return true;
            }

        // Render filled polygon
        bool render_filled_polygon(
                short* vx, short* vy,
                int n,
                int r, int g, int b, int alpha) override
            {
                return true;
            }

    };
} // namespace MediaLayer
#endif
