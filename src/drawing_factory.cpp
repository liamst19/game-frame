/** drawing_factory.h
 * 
 */

#include "drawing_factory.h"

// Constructor
DrawingFactory::DrawingFactory(MediaLayer* media_layer):
_media_layer(media_layer)
{

}

// Destructor
DrawingFactory::~DrawingFactory()
{

}

PointDrawing DrawingFactory::getPoint(int x, int y, int r, int g, int b, int alpha)
{
    PointDrawing point{x, y, r, g, b, alpha};
    return point;
}