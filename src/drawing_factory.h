/** drawing_factory.h
 * 
 */

#ifndef DRAWING_FACTORY_H
#define DRAWING_FACTORY_H

#include "medialayer_drawing_renderer.h"
#include "drawing.h"
#include "drawing_point.h"
#include "drawing_line.h"

class DrawingFactory
{

    MediaLayer_Drawing_Renderer* _drawing_renderer;

public:

    // Constructor
    DrawingFactory(MediaLayer_Drawing_Renderer* renderer);

    // Destructor
    ~DrawingFactory();

    // Create PointDrawing object
    PointDrawing getPoint(int x, int y, int r, int g, int b, int alpha);

    // Create HLine object
    LineDrawing getLine(int aX, int aY, int bX, int bY, int r, int g, int b, int alpha);

};
#endif