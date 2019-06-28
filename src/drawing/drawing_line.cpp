/** drawing_line.cpp
 *  Object for rendering line to screen.
 */
#include "drawing_line.h"

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"
#include "../util/math.h"

namespace Drawing{

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @aX, @aY, @bX, @bY: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
    LineDrawing::LineDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             int aX, int aY, 
                             int bX, int bY, 
                             int r, int g, int b, int alpha):
        DrawingElement(renderer, Color{r, g, b, alpha}),
        _point_a(Position{aX, aY}),
        _point_b(Position{bX, bY})
    {
    }

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @a, @b: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
    LineDrawing::LineDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             Position a, 
                             Position b, 
                             Color color):
        DrawingElement(renderer, color),
        _point_a(a),
        _point_b(b)
    {
    }

/** Destructor
 */
    LineDrawing::~LineDrawing()
    {
    }

/** Public function: render()
 *  Renders line to screen.
 */
    bool LineDrawing::render(int x, int y, double rotation)
    {
        // Render line
        return _drawing_renderer->render_line(
                _point_a.x, _point_a.y,
                _point_b.x, _point_b.y,
                _color.r, _color.g, _color.b, _color.alpha);
    }

/** public function: a()
 *  End point of line ab.
 */
    Position LineDrawing::a()
    {
        return _point_a;
    }

/** public function: b()
 *  End point of line ab.
 */
    Position LineDrawing::b()
    {
        return _point_b;
    }

    /** public function: width()
     * Width of the element
     */
    int LineDrawing::width()
    {
        int width = _point_b.x - _point_a.x;
        if(width < 0)
        {
            width *= -1;
        }
        return width;        
    }

    /** public function: height()
     * Height of the element
     */
    int LineDrawing::height()
    {
        int height = _point_b.y - _point_a.y;
        if(height < 0)
        {
            height *= -1;
        }
        return height;        
    }

    /** public function: center()
     * Position of the center of element
     */
    Position LineDrawing::center()
    {
        return Position{(_point_a.x + _point_b.x) / 2, (_point_a.y + _point_b.y) / 2};
    }
    
    /** public function: min()
     * Position of the upper left corner
     */
    Position LineDrawing::min()
    {
        int x, y;
        x = _point_a.x < _point_b.x ? _point_a.x : _point_b.x; 
        y = _point_a.y < _point_b.y ? _point_a.y : _point_b.y; 

        return Position{x, y};
    }

    /** public function: max()
     * Position of the lower right corner
     */
    Position LineDrawing::max()
    {
        int x, y;
        x = _point_b.x > _point_a.x ? _point_b.x : _point_a.x; 
        y = _point_b.y > _point_a.y ? _point_b.y : _point_a.y; 

        return Position{x, y};
    }
    
} // namespace Drawing
