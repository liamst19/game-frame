/** drawing_rectangle.cpp
 *  Class for rendering rectangle to screen.
 */

#include "drawing_rectangle.h"

#include "drawing_element.h"
#include "medialayer_drawing_renderer.h"

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @aX, @aY, @bX, @bY: Coordinates of the opposing vertices.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: renders a solid shape if true, line if false
 */
RectangleDrawing::RectangleDrawing(
    MediaLayer_Drawing_Renderer* renderer, 
    int aX, int aY, 
    int bX, int bY, 
    int r, int g, int b, int alpha,
    bool fill):
  DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha}),
  _point_a(DrawingElement::Position{aX, aY}),
  _point_b(DrawingElement::Position{bX, bY}),
  _fill_shape(fill)
{
}

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @a, @b: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 *    @fill: renders a solid shape if true, line if false
 */
RectangleDrawing::RectangleDrawing(
    MediaLayer_Drawing_Renderer* renderer, 
    DrawingElement::Position a, 
    DrawingElement::Position b, 
    DrawingElement::Color color,
    bool fill):
  DrawingElement(renderer, color),
  _point_a(a),
  _point_b(b),
  _fill_shape(fill)
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
bool RectangleDrawing::render()
{
    // Render rectangle
    return _drawing_renderer->render_rectangle(
                                _point_a.x, _point_a.y,
                                _point_b.x, _point_b.y,
                                _color.r, _color.g, _color.b, _color.alpha,
                                _fill_shape);
}

/** public function: a()
 *  Coordinates of a vertice of the rectangle
 */
DrawingElement::Position RectangleDrawing::a()
{
    return _point_a;
}

/** public function: b()
 *  Coordinates of a vertice of the rectangle
 */
DrawingElement::Position RectangleDrawing::b()
{
    return _point_b;
}