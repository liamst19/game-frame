/** drawing_text.h
 *  
 * 
 */

#ifndef DRAWING_TEXT_H
#define DRAWING_TEXT_H

#include <string>

#include "drawing_element.h"
#include "medialayer_drawing_renderer.h"

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
        DrawingElement::Position position, 
        DrawingElement::Color color);

    // Destructor
    ~TextDrawing();

    // Update text
    void update(
        std::string text,
        std::string font_src, int fon_size,
        DrawingElement::Position position, 
        DrawingElement::Color color);

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
    DrawingElement::Position position();

    // Set text position
    void set_position(DrawingElement::Position position);
    
    // Index for referring back to cache of textures.
    //   -- But is this necessary to be public?
    int texture_index();

private:

    std::string _text;
    std::string _font_src;
    int _font_size;
    DrawingElement::Position _position;

    // Index for referring back to cache
    int _texture_index;

    // Initialize texture in renderer
    void _initialize_texture();

    // Update texture in renderer
    void _update_texture();

};
#endif
