/** drawing_text.cpp
 *  Object for rendering text to screen.
 */
#include "drawing_text.h"

#include <string>
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *   @text: Text content
 *   @ font_src, @font_size: Font source and size
 *   @x, @y: Text position
 *   @r, @g, @b, @alpha: Text color
 */
    TextDrawing::TextDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             std::string text,
                             std::string font_src, int font_size,
                             int x, int y, 
                             int r, int g, int b, int alpha):
        DrawingElement(renderer, Color{r, g, b, alpha}),
        _text(text),
        _font_src(font_src),
        _font_size(font_size),
        _position(Position{x, y})
    {
        _initialize();
    }

/** Constructor
 *   @text: Text content
 *   @ font_src, @font_size: Font source and size
 *   @position: Text position
 *   @color: Text color
 */
    TextDrawing::TextDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             std::string text,
                             std::string font_src, int font_size,
                             Position position, 
                             Color color):
        DrawingElement(renderer, color),
        _text(text),
        _font_src(font_src),
        _font_size(font_size),
        _position(position)
    {
        _initialize();
    }

/** Destructor 
 */
    TextDrawing::~TextDrawing()
    {}

/** private function: _initialize()
 * Initializes text object
 */
    void TextDrawing::_initialize()
    {
        _initialize_texture();
    }

/** private function: _initialize_texture
 * Initializes texture in renderer
 */
    void TextDrawing::_initialize_texture()
    {
        int index = -1;
        index = _drawing_renderer
            ->initialize_text(_text,
                              _font_src, _font_size,
                              _position.x, _position.y,
                              _color.r, _color.g, _color.b, _color.alpha);

        if(index > 0)
        {
            _texture_index = index;
        }
        else
        {
            // Something went wrong, throw exception?
        }
    }

/** private function: _update_texture
 * Updates texture in renderer
 */
    void TextDrawing::_update_texture()
    {
        bool result = false;
        result = _drawing_renderer
            ->update_text(_texture_index,
                          _text,
                          _font_src, _font_size,
                          _color.r, _color.g, _color.b, _color.alpha);

        if(!result)
        {
            // Something went wrong, throw exception?
        }
    }

/** public function: render()
 * Renders text to screen 
 */
    bool TextDrawing::render(int x, int y, double rotation)
    {
        return _drawing_renderer
            ->render_text(_texture_index,
                          _position.x, _position.y);
    }

/** public function: text()
 * Text content
 */
    std::string TextDrawing::text()
    {
        return _text;
    }

/** public function: update()
 * update text
 */
    void TextDrawing::update(std::string text)
    {
        _text = text;
        bool result = false;
        _update_texture();
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
    Position TextDrawing::position()
    {
        return _position;
    }

/** public function: set_position()
 * Sets text position
 *   @position: Text position
 */
    void TextDrawing::set_position(Position position)
    {
        _position = position;
    }

/** public function: texture_index
 * Gets index for referring to cache of textures
 * stored in the renderer
 */
    int TextDrawing::texture_index()
    {
        return _texture_index;
    }

    /** public function: width()
     * Returns width
     */
    int TextDrawing::width()
    {
        return _drawing_renderer->texture_width(_texture_index);
    }
    
    /** public function: height()
     * Returns height
     */
    int TextDrawing::height()
    {
        return _drawing_renderer->texture_height(_texture_index);
    }

    /** public function: center()
     * Returns position of the center of text
     */
    Position TextDrawing::center()
    {
        return Position{_position.x + (width()/2), _position.y + (height()/2)};
    }
    
    /** public function: min()
     * Position of the upper left corner
     */
    Position TextDrawing::min()
    {
        return _position;
    }

    /** public function: max()
     * Position of the lower right corner
     */
    Position TextDrawing::max()
    {
        return Position{_position.x + width(), _position.y + height()};
    }

} // namespace Drawing
