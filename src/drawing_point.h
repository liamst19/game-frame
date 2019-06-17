/** drawing_point.h
 *  Class for rendering single pixel to screen.
  */

#ifndef DRAWING_POINT_H
#define DRAWING_POINT_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class PointDrawing: public Drawing
{

public:

    // Constructor
    PointDrawing(MediaLayer_Drawing_Renderer* renderer, 
        int x, int y, 
        int r, int g, int b, int alpha);

    // Constructor
    PointDrawing(MediaLayer_Drawing_Renderer* renderer, 
        Drawing::Point coordinates, 
        Drawing::Color color);

    // Destructor
    ~PointDrawing();

    // Renders point to screen
    bool render() override;

    // Coordinates of the point
    Drawing::Point coordinates();

    // X-coordinate of the point
    int x();

    // Y-coordinate of the point
    int y();

private:

    Drawing::Point _point_coordinates;

};
#endif