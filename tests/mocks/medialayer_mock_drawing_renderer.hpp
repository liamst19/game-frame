/** medialayer_mock_drawing_renderer.hpp
 * Mock MediaLayer Object
 */

#ifndef MEDIALAYER_MOCK_DRAWING_RENDERER_H
#define MEDIALAYER_MOCK_DRAWING_RENDERER_H

#include <string>
#include "../../src/medialayer/medialayer_drawing_renderer.h"

namespace MediaLayer{

    class Mock_Drawing_Renderer: public Drawing_Renderer
    {
    private:
        int _retval{0};
        
    public:

        Mock_Drawing_Renderer(){}

        ~Mock_Drawing_Renderer(){}

        // Get width of a texture
        int texture_width(int texture_index) override
            {
                return _retval;
            }

        // Get height of a texture
        int texture_height(int texture_index) override
            {
                return _retval;
            }

        // Initialize texture for rendering text, returns index for
        // reference
        int initialize_text(
                std::string text,
                std::string font_src, int font_size,
                int x, int y,
                int r, int g, int b, int alpha) override
            {
                return _retval;
            }

        // Update text of an existing texture
        bool update_text(
                int texture_index,
                std::string text,
                std::string font_src, int font_size,
                int r, int g, int b, int alpha) override
            {
                return true;
            }

        // Render Text to screen
        bool render_text(
                int texture_index,
                int x, int y) override
            {
                return true;
            }


        // Initialize texture for image
        int initialize_image(
                std::string source_path) override
            {
                return _retval;
            }

        // Render Image to screen
        bool render_image(
                int texture_index,
                int x, int y) override
            {
                return true;
            }

        // Render point
        bool render_point(
                int x, int y,
                int r, int g, int b, int alpha) override
            {
                return true;
            }

        // Render line
        bool render_line(
                int aX, int aY,
                int bX, int bY,
                int r, int g, int b, int alpha,
                int thickness =1) override
            {
                return true; 
            }

        // Render rectangle outline
        bool render_rectangle(
                int aX, int aY,
                int bX, int bY,
                int r, int g, int b, int alpha) override
            {
                return true; 
            }

        // Render circle
        bool render_circle(
                int centerX, int centerY,
                int radius,
                int r, int g, int b, int alpha) override
            {
                return true; 
            }

        // Render ellipse
        bool render_ellipse(
                int aX, int aY,
                int bX, int bY,
                int r, int g, int b, int alpha) override
            {
                return true; 
            }

        // Render rectangle outline
        bool render_filled_rectangle(
                int aX, int aY,
                int bX, int bY,
                int r, int g, int b, int alpha) override
            {
                return true; 
            }

        // Render circle
        bool render_filled_circle(
                int centerX, int centerY,
                int radius,
                int r, int g, int b, int alpha) override
            {
                return true; 
            }

        // Render ellipse
        bool render_filled_ellipse(
                int aX, int aY,
                int bX, int bY,
                int r, int g, int b, int alpha) override
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
