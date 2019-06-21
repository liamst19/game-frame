/** drawing_text.cpp
 *  Object for rendering text to screen.
 */
#include "drawing_text.h"

#include <string>
#include "drawing_element.h"
#include "medialayer_drawing_renderer.h"

// Constructor
TextDrawing::TextDrawing(MediaLayer_Drawing_Renderer* renderer, 
    std::string text,
    std::string font_src, int font_size,
    int x, int y, 
    int r, int g, int b, int alpha):
    DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha}),
    _text(text),
    _font_src(font_src),
    _font_size(font_size),
    _position(DrawingElement::Position{x, y})
{}

// Constructor
TextDrawing::TextDrawing(MediaLayer_Drawing_Renderer* renderer, 
    std::string text,
    std::string font_src, int font_size,
    DrawingElement::Position position, 
    DrawingElement::Color color):
    DrawingElement(renderer, color),
    _text(text),
    _font_src(font_src),
    _font_size(font_size),
    _position(position)
{}

// Destructor
TextDrawing::~TextDrawing()
{}

// Renders text to screen
bool TextDrawing::render()
{
    return _drawing_renderer->render_text(
            _text,
            _font_src, _font_size,
            _position.x, _position.y,
            _color.r, _color.g, _color.b, _color.alpha);
}

std::string TextDrawing::text()
{
    return _text;
}

void TextDrawing::set_text(std::string text)
{
    _text = text;
}

std::string TextDrawing::font_src()
{
    return _font_src;
}

void TextDrawing::set_font(std::string source_path, int size)
{
    _font_src = source_path;
    set_font_size(size);
}

int TextDrawing::font_size()
{
    return _font_size;
}

void TextDrawing::set_font_size(int size)
{
    _font_size = size;
}

// End point of line ab
DrawingElement::Position TextDrawing::position()
{
    return _position;
}

void TextDrawing::set_position(DrawingElement::Position position)
{
    _position = position;
}