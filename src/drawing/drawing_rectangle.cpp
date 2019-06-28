/** drawing_rectangle.cpp
 *  Class for rendering rectangle to screen.
 */

#include "drawing_rectangle.h"

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @aX, @aY, @bX, @bY: Coordinates of the opposing vertices.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: renders a solid shape if true, line if false
 */
    RectangleDrawing::RectangleDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
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
    RectangleDrawing::RectangleDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
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
    RectangleDrawing::~RectangleDrawing()
    {
    }

/** Public function: render()
 *  Renders rectangle to screen
 */
    bool RectangleDrawing::render(int x, int y, double rotation)
    {
        // Render rectangle
        return _drawing_renderer->render_rectangle(
                _point_a.x, _point_a.y,
                _point_b.x, _point_b.y,
                _color.r, _color.g, _color.b, _color.alpha);
    }

/** public function: a()
 *  Coordinates of a vertice of the rectangle
 */
    Position RectangleDrawing::a()
    {
        return _point_a;
    }

/** public function: b()
 *  Coordinates of a vertice of the rectangle
 */
    Position RectangleDrawing::b()
    {
        return _point_b;
    }

    /** public function: width()
     * Width of the element
     */
    int RectangleDrawing::width()
    {
        return (_point_b.x > _point_a.x) ? (_point_b.x - _point_a.x) : (_point_a.x - _point_b.x);
    }

    /** public function: height()
     * Height of the element
     */
    int RectangleDrawing::height()
    {
        return (_point_b.y > _point_a.y) ? (_point_b.y - _point_a.y) : (_point_a.y - _point_b.y);
    }

    /** public function: center()
     * Position of the center of element
     */
    Position RectangleDrawing::center()
    {
        return Position{(_point_a.x + _point_b.x) / 2, (_point_a.y + _point_b.y) / 2};
    }
    
    /** public function: min()
     * Position of the upper left corner
     */
    Position RectangleDrawing::min()
    {
        int x, y;
        x = _point_a.x < _point_b.x ? _point_a.x : _point_b.x; 
        y = _point_a.y < _point_b.y ? _point_a.y : _point_b.y; 

        return Position{x, y};
    }

    /** public function: max()
     * Position of the lower right corner
     */
    Position RectangleDrawing::max()
    {
        int x, y;
        x = _point_b.x > _point_a.x ? _point_b.x : _point_a.x; 
        y = _point_b.y > _point_a.y ? _point_b.y : _point_a.y; 

        return Position{x, y};
    }

} // namespace Drawing
