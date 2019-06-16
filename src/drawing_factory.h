/** drawing_factory.h
 * 
 */

#ifndef DRAWING_FACTORY_H
#define DRAWING_FACTORY_H

#include "medialayer.h"
#include "drawing.h"
#include "drawing_point.h"

class DrawingFactory
{

    MediaLayer* _media_layer;

public:

    // Constructor
    DrawingFactory(MediaLayer *media_layer);

    // Destructor
    ~DrawingFactory();

    // Create PointDrawing object
    PointDrawing getPoint(int x, int y, int r, int g, int b, int alpha);

    // Create HLine object
    // LineDrawing getHLine(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha);

};
#endif