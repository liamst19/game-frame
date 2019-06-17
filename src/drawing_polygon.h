/** drawing_polygon.h
 *  Class for rendering polygon to screen
 */

#ifndef DRAWING_POLYGON_H
#define DRAWING_POLYGON_H

#include "drawing.h"
#include "medialayer_drawing_renderer.h"

class PolygonDrawing: public Drawing
{

public:

    // Constructor
    PolygonDrawing(MediaLayer_Drawing_Renderer* renderer, 
                   int r, int g, int b, int alpha,
                   bool fill = false);

    // Constructor
    PolygonDrawing(MediaLayer_Drawing_Renderer* renderer, 
                   Drawing::Color color,
                   bool fill = false);

    // Destructor
    ~PolygonDrawing();

    // Renders line to screen
    bool render() override;

private:

    // Renders solid shape if true, outline if false 
    bool _fill_shape;

};
#endif