/** drawing_text.cpp
 *  Object for rendering text to screen.
 */
#include "drawing_text.h"

#include <string>
#include "drawing_element.h"
#include "medialayer_drawing_renderer.h"

/** Constructor
 *   @text: Text content
 *   @ font_src, @font_size: Font source and size
 *   @x, @y: Text position
 *   @r, @g, @b, @alpha: Text color
 */
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

/** Constructor
 *   @text: Text content
 *   @ font_src, @font_size: Font source and size
 *   @position: Text position
 *   @color: Text color
 */
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

/** Destructor 
 */
TextDrawing::~TextDrawing()
{}

/** public function: render()
 * Renders text to screen 
 */
bool TextDrawing::render()
{
    return _drawing_renderer->render_text(
            _text,
            _font_src, _font_size,
            _position.x, _position.y,
            _color.r, _color.g, _color.b, _color.alpha);
}

/** public function: text()
 * Text content
 */
std::string TextDrawing::text()
{
    return _text;
}

/** public function: set_text()
 * Set text content
 */
void TextDrawing::set_text(std::string text)
{
    _text = text;
}

/** public function: font_src()
 * Location of font file
 */
std::string TextDrawing::font_src()
{
    return _font_src;
}

/** public function: set_font
 * Sets font file source and font size
 *   @source_path: Path of font file
 *   @size: font size
 */
void TextDrawing::set_font(std::string source_path, int size)
{
    _font_src = source_path;
    set_font_size(size);
}

/** public function: font_size
 * Font size
 */
int TextDrawing::font_size()
{
    return _font_size;
}

/** public function: set_font_size
 * Sets font size
 *   @font_size: Font size
 */
void TextDrawing::set_font_size(int size)
{
    _font_size = size;
}

/** public function: position
 * Text position
 */
DrawingElement::Position TextDrawing::position()
{
    return _position;
}

/** public function: set_position()
 * Sets text position
 *   @position: Text position
 */
void TextDrawing::set_position(DrawingElement::Position position)
{
    _position = position;
}