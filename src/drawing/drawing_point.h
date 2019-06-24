/** drawing_point.h
 *  Class for rendering single pixel to screen.
  */

#ifndef DRAWING_POINT_H
#define DRAWING_POINT_H

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

class PointDrawing: public DrawingElement
{

public:

    // Constructor
    PointDrawing(MediaLayer::Drawing_Renderer* renderer, 
        int x, int y, 
        int r, int g, int b, int alpha);

    // Constructor
    PointDrawing(MediaLayer::Drawing_Renderer* renderer, 
        DrawingElement::Position coordinates, 
        DrawingElement::Color color);

    // Destructor
    ~PointDrawing();

    // Renders point to screen
    bool render() override;

    // Coordinates of the point
    DrawingElement::Position coordinates();

    // X-coordinate of the point
    int x();

    // Y-coordinate of the point
    int y();

private:

    DrawingElement::Position _point_coordinates;

};
#endif
