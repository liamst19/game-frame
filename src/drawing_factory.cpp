/** drawing_factory.h
 * 
 */

#include "drawing_factory.h"

// Constructor
DrawingFactory::DrawingFactory(MediaLayer_Drawing_Renderer* renderer):
_drawing_renderer(renderer)
{
}

// Destructor
DrawingFactory::~DrawingFactory()
{
}

PointDrawing DrawingFactory::getPoint(int x, int y, int r, int g, int b, int alpha)
{
    PointDrawing point{_drawing_renderer, x, y, r, g, b, alpha};
    return point;
}

LineDrawing DrawingFactory::getLine(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha)
{
    LineDrawing line{_drawing_renderer, aX, aY, bX, bY, r, g, b, alpha};
    return line;
}