/** drawing_line.cpp
 *  Object for rendering line to screen.
 */
#include "drawing_line.h"

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

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
        DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha}),
        _point_a(DrawingElement::Position{aX, aY}),
        _point_b(DrawingElement::Position{bX, bY})
    {
    }

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @a, @b: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
    LineDrawing::LineDrawing(MediaLayer::Drawing_Renderer* renderer, 
                             DrawingElement::Position a, 
                             DrawingElement::Position b, 
                             DrawingElement::Color color):
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
    bool LineDrawing::render()
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
    DrawingElement::Position LineDrawing::a()
    {
        return _point_a;
    }

/** public function: b()
 *  End point of line ab.
 */
    DrawingElement::Position LineDrawing::b()
    {
        return _point_b;
    }

} // namespace Drawing
