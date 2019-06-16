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
    PointDrawing point{x, y, r, g, b, alpha, _drawing_renderer};
    return point;
}