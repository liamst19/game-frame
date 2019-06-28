/** drawing_text.h
 *  
 * 
 */

#ifndef DRAWING_TEXT_H
#define DRAWING_TEXT_H

#include <string>

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class TextDrawing: public DrawingElement
    {

    public:

        // Constructor
        TextDrawing(MediaLayer::Drawing_Renderer* renderer, 
                    std::string text,
                    std::string font_src, int font_size,
                    int x, int y, 
                    int r, int g, int b, int alpha);

        // Constructor
        TextDrawing(MediaLayer::Drawing_Renderer* renderer, 
                    std::string text,
                    std::string font_src, int fon_size,
                    Position position, 
                    Color color);

        // Destructor
        ~TextDrawing();

        // Update text
        void update(std::string text,
                    std::string font_src, int fon_size,
                    Position position, 
                    Color color);

        // Set text content
        void update(std::string text);

        // Renders text to screen
        bool render() override;

        // Text content
        std::string text();

        // Location of font file
        std::string font_src();

        // Set location of font file
        void set_font(std::string source_path, int size);

        // Font size
        int font_size();

        // Set font size
        void set_font_size(int size);

        // Text position
        Position position();

        // Set text position
        void set_position(Position position);
    
        // Index for referring back to cache of textures.
        //   -- But is this necessary to be public?
        int texture_index();

        int width() override;

        int height() override;

        Position center() override;

    private:

        std::string _text;
        std::string _font_src;
        int _font_size;
        Position _position;

        // Index for referring back to cache
        int _texture_index;

        // Initialize Text Object
        void _initialize();

        // Initialize texture in renderer
        void _initialize_texture();

        // Update texture in renderer
        void _update_texture();

    };

} // namespace Drawing
#endif
