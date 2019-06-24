/** drawing_factory.h
 * 
 *  Collection of methods that return Drawing objects for
 *  rendering to screen.
 * 
 */

#ifndef DRAWING_FACTORY_H
#define DRAWING_FACTORY_H

#include "../medialayer/medialayer_drawing_renderer.h"

#include "drawing_point.h"
#include "drawing_line.h"
#include "drawing_rectangle.h"
#include "drawing_rectangle_filled.h"
#include "drawing_ellipse.h"
#include "drawing_ellipse_filled.h"
#include "drawing_polygon.h"
#include "drawing_polygon_filled.h"

namespace Drawing{

    class DrawingFactory{

    public:

        // Constructor
        DrawingFactory(MediaLayer::Drawing_Renderer* renderer);

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
                int r, int g, int b, int alpha);

        // Create Rectangle
        FilledRectangleDrawing getFilledRectangle(
                int aX, int aY, 
                int bX, int bY, 
                int r, int g, int b, int alpha);

        // Create Ellipse
        EllipseDrawing getEllipse(
                int x, int y, 
                int radiusX, int radiusY, 
                int r, int g, int b, int alpha);
    
        // Create Ellipse
        FilledEllipseDrawing getFilledEllipse(
                int x, int y, 
                int radiusX, int radiusY, 
                int r, int g, int b, int alpha);
    
        // Create Circle
        EllipseDrawing getCircle(
                int x, int y, 
                int radius, 
                int r, int g, int b, int alpha);

        // Create Circle
        FilledEllipseDrawing getFilledCircle(
                int x, int y, 
                int radius, 
                int r, int g, int b, int alpha);

    private:

        // Handles screen output
        MediaLayer::Drawing_Renderer* _drawing_renderer;

    };

} // namespace Drawing
#endif
