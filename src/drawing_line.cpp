/** drawing_line.cpp
 *  Object for rendering line to screen.
 */

#include "drawing_line.h"

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @aX, @aY, @bX, @bY: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
LineDrawing::LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
    int aX, int aY, 
    int bX, int bY, 
    int r, int g, int b, int alpha):
  Drawing(renderer, Drawing::Color{r, g, b, alpha}),
  _point_a(Drawing::Point{aX, aY}),
  _point_b(Drawing::Point{bX, bY})
{
}

/** Constructor
 *    @renderer: Pointer to object handling screen output. 
 *    @a, @b: Coordinates of the endpoints.
 *    @r, @g, @b, @alpha: Color and alpha transparency values.
 */
LineDrawing::LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
    Drawing::Point a, 
    Drawing::Point b, 
    Drawing::Color color):
  Drawing(renderer, color),
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
Drawing::Point LineDrawing::a()
{
    return _point_a;
}

/** public function: b()
 *  End point of line ab.
 */
Drawing::Point LineDrawing::b()
{
    return _point_b;
}