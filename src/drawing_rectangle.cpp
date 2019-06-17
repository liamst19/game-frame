/** drawing_rectangle.cpp
 * 
 */

#include "drawing_rectangle.h"

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

RectangleDrawing::RectangleDrawing(
    MediaLayer_Drawing_Renderer* renderer, 
    int aX, int aY, 
    int bX, int bY, 
    int r, int g, int b, int alpha,
    bool fill):
  Drawing(renderer),
  _point_a(Drawing::Point{aX, aY}),
  _point_b(Drawing::Point{bX, bY}),
  _color(Drawing::Color{r, g, b, alpha}),
  _fill_shape(fill)
{
}

RectangleDrawing::RectangleDrawing(
    MediaLayer_Drawing_Renderer* renderer, 
    Drawing::Point a, 
    Drawing::Point b, 
    Drawing::Color color,
    bool fill):
  Drawing(renderer),
  _point_a(a),
  _point_b(b),
  _color(color),
  _fill_shape(fill)
{
}

RectangleDrawing::~RectangleDrawing()
{
}

// Renders rectangle to screen
bool RectangleDrawing::render()
{
    // Render rectangle
    return _drawing_renderer->render_rectangle(
                                _point_a.x, _point_a.y,
                                _point_b.x, _point_b.y,
                                _color.r, _color.g, _color.b, _color.alpha,
                                _fill_shape);
}

Drawing::Point RectangleDrawing::a()
{
    return _point_a;
}

Drawing::Point RectangleDrawing::b()
{
    return _point_b;
}

Drawing::Color RectangleDrawing::color()
{
    return _color;
}