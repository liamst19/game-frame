/** drawing_line.h
 *  Object for rendering line to screen.
 * 
 *  Currently this renders only a straight line of 1px thickness.
 * 
 *  Possibile future plans:
 *   - thickness
 *   - option for drawing curved line
 * 
 */

#ifndef DRAWING_LINE_H
#define DRAWING_LINE_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class LineDrawing: public Drawing
{

public:

    // Constructor
    LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
        int aX, int aY, 
        int bX, int bY, 
        int r, int g, int b, int alpha);

    // Constructor
    LineDrawing(MediaLayer_Drawing_Renderer* renderer, 
        Drawing::Point a, 
        Drawing::Point b, 
        Drawing::Color color);

    // Destructor
    ~LineDrawing();

    // Renders line to screen
    bool render() override;

    // End point of line ab
    Drawing::Point a();

    // End point of line ab
    Drawing::Point b();

private:

    Drawing::Point _point_a, _point_b;

};
#endif