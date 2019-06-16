/** drawing_line.cpp
 * 
 */

#include "drawing_line.h"

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

LineDrawing::LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
                         int aX, 
                         int aY, 
                         int bX, 
                         int bY, 
                         int r, 
                         int g, 
                         int b, 
                         int alpha):
  Drawing(renderer),
  _point_a(Drawing::Point{aX, aY}),
  _point_b(Drawing::Point{bX, bY}),
  _color(Drawing::Color{r, g, b, alpha})
{
}

LineDrawing::LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
                         Drawing::Point a, 
                         Drawing::Point b, 
                         Drawing::Color color):
  Drawing(renderer),
  _point_a(a),
  _point_b(b),
  _color(color)
{
}

LineDrawing::~LineDrawing()
{
}

// Renders line to screen
bool LineDrawing::render()
{
    // Render line
    return _drawing_renderer->render_line(_point_a.x,
                                          _point_a.y,
                                          _point_b.x,
                                          _point_b.y,
                                          _color.r,
                                          _color.g,
                                          _color.b,
                                          _color.alpha);
}

Drawing::Point LineDrawing::a()
{
    return _point_a;
}

Drawing::Point LineDrawing::b()
{
    return _point_b;
}

Drawing::Color LineDrawing::color()
{
    return _color;
}