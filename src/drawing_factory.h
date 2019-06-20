/** drawing_factory.h
 * 
 *  Collection of methods that return Drawing objects for
 *  rendering to screen.
 * 
 */

#ifndef DRAWING_FACTORY_H
#define DRAWING_FACTORY_H

#include "medialayer_drawing_renderer.h"
#include "drawing_element.h"
#include "drawing_point.h"
#include "drawing_line.h"
#include "drawing_ellipse.h"
#include "drawing_rectangle.h"
// #include "drawing_polygon.h"

class DrawingFactory{

public:

    // Constructor
    DrawingFactory(MediaLayer_Drawing_Renderer* renderer);

    // Destructor
    ~DrawingFactory();

    // Create PointDrawing object
    PointDrawing getPoint(
                    int x, int y, 
                    int r, int g, int b, int alpha);

    // Create Line object
    LineDrawing getLine(
                    int aX, int aY, 
                    int bX, int bY, 
                    int r, int g, int b, int alpha);

    // Create Rectangle
    RectangleDrawing getRectangle(
                    int aX, int aY, 
                    int bX, int bY, 
                    int r, int g, int b, int alpha,
                    bool fill = false);

    // Create Ellipse
    EllipseDrawing getEllipse(
                    int x, int y, 
                    int radiusX, int radiusY, 
                    int r, int g, int b, int alpha,
                    bool fill = false);
    
    // Create Circle
    EllipseDrawing getCircle(
                    int x, int y, 
                    int radius, 
                    int r, int g, int b, int alpha,
                    bool fill = false);

private:

    // Handles screen output
    MediaLayer_Drawing_Renderer* _drawing_renderer;

};
#endif