/** drawing_polygon.h
 *  Class for rendering polygon to screen
 */

#ifndef DRAWING_POLYGON_H
#define DRAWING_POLYGON_H

#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class PolygonDrawing: public DrawingElement
    {

    public:

        // Constructor
        PolygonDrawing(MediaLayer::Drawing_Renderer* renderer, 
                       int r, int g, int b, int alpha,
                       bool fill = false);

        // Constructor
        PolygonDrawing(MediaLayer::Drawing_Renderer* renderer, 
                       DrawingElement::Color color,
                       bool fill = false);

        // Destructor
        ~PolygonDrawing();

        // Renders line to screen
        bool render() override;

    private:

        // Renders solid shape if true, outline if false 
        bool _fill_shape;

    };

} // namespace Drawing
#endif
