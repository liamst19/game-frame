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
    TextDrawing(MediaLayer_Drawing_Renderer* renderer, 
        std::string text,
        std::string font_src, int fon_size,
        int x, int y, 
        int r, int g, int b, int alpha);

    // Constructor
    TextDrawing(MediaLayer_Drawing_Renderer* renderer, 
        std::string text,
        std::string font_src, int fon_size,
        DrawingElement::Position position, 
        DrawingElement::Color color);

    // Destructor
    ~TextDrawing();

    // Renders text to screen
    bool render() override;

    std::string text();

    void set_text(std::string text);

    std::string font_src();

    void set_font(std::string source_path, int size);

    int font_size();

    void set_font_size(int size);

    // End point of line ab
    DrawingElement::Position position();

    void set_position(DrawingElement::Position position);

private:

    std::string _text;
    std::string _font_src;
    int _font_size;
    DrawingElement::Position _position;

};
#endif