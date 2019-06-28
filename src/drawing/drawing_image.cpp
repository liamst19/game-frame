/** drawing_image.cpp
 *  Object for rendering image to screen.
 */
#include "drawing_image.h"

#include <string>
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *   @source_path, @font_size: Font source and size
 *   @x, @y: Image position
 */
    ImageDrawing::ImageDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            std::string source_path,
            int x, int y):
        DrawingElement(renderer, Color{0, 0, 0, 0}),
        _source_path(source_path),
        _position(Position{x, y})
    {
        _initialize();
    }

/** Constructor
 *   @ source_path, @font_size: Font source and size
 *   @position: Image position
 */
    ImageDrawing::ImageDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            std::string source_path,
            Position position):
        DrawingElement(renderer, Color{0, 0, 0, 0}),
        _source_path(source_path),
        _position(position)
    {
        _initialize();
    }

/** Destructor 
 */
    ImageDrawing::~ImageDrawing()
    {}

/** private function: _initialize()
 * Initializes text object
 */
    void ImageDrawing::_initialize()
    {
        _initialize_texture();
    }

/** private function: _initialize_texture
 * Initializes texture in renderer
 */
    void ImageDrawing::_initialize_texture()
    {
        _texture_index = _drawing_renderer
            ->initialize_image(_source_path);

        if(_texture_index < 0)
        {
            // Something went wrong, throw exception?
        }
    }

/** public function: render()
 * Renders image to screen 
 */
    bool ImageDrawing::render(int x, int y, double rotation)
    {
        return _drawing_renderer
            ->render_image(_texture_index,
                           _position.x, _position.y);
    }

/** public function: source_path()
 * Location of image file
 */
    std::string ImageDrawing::image_source_path()
    {
        return _source_path;
    }

/** public function: set_ image_source()
 * Sets image file source
 *   @source_path: Path of font file
 */
    void ImageDrawing::set_image_source(
            std::string source_path)
    {
        _source_path = source_path;
    }

/** public function: position
 * Image position
 */
    Position ImageDrawing::position()
    {
        return _position;
    }

/** public function: set_position()
 * Sets position
 *   @position: Image position
 */
    void ImageDrawing::set_position(
            Position position)
    {
        _position = position;
    }

/** public function: texture_index
 * Gets index for referring to cache of textures
 * stored in the renderer
 */
    int ImageDrawing::texture_index()
    {
        return _texture_index;
    }

    /** public function: width()
     * Returns width
     */
    int ImageDrawing::width()
    {
        return _drawing_renderer->texture_width(_texture_index);
    }
    
    /** public function: height()
     * Returns height
     */
    int ImageDrawing::height()
    {
        return _drawing_renderer->texture_height(_texture_index);
    }

    /** public function: center()
     * Returns position of center 
     */
    Position ImageDrawing::center()
    {
        return Position{_position.x + (width()/2), _position.y + (height()/2)};
    }
    
    /** public function: min()
     * Position of the upper left corner
     */
    Position ImageDrawing::min()
    {
        return _position;
    }

    /** public function: max()
     * Position of the lower right corner
     */
    Position ImageDrawing::max()
    {
        return Position{_position.x + width(), _position.y + height()};
    }


} // namespace Drawing
