/** drawing_line.h
 * 
 */

#ifndef DRAWING_LINE_H
#define DRAWING_LINE_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class LineDrawing: public Drawing
{

public:

    LineDrawing(MediaLayer_Drawing_Renderer* renderer, int aX, int aY, int bX, int bY, int r, int g, int b, int alpha);

    LineDrawing(MediaLayer_Drawing_Renderer* renderer, Drawing::Point a, Drawing::Point b, Drawing::Color color);

    ~LineDrawing();

    // Renders line to screen
    bool render() override;

    Drawing::Point a();

    Drawing::Point b();

    Drawing::Color color();

private:

    Drawing::Point _point_a, _point_b;
    Drawing::Color _color;

};
#endif