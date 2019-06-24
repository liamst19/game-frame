/** drawing_polygon_filled.h
 *  Class for rendering polygon to screen
 */

#ifndef DRAWING_POLYGON_FILLED_H
#define DRAWING_POLYGON_FILLED_H

#include <vector>
#include "drawing_polygon.h"
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class FilledPolygonDrawing: public PolygonDrawing
    {

    public:

        // Constructor
        FilledPolygonDrawing(MediaLayer::Drawing_Renderer* renderer, 
                       int* vx, int* vy, int n,
                       int r, int g, int b, int alpha);

        // Constructor
        FilledPolygonDrawing(MediaLayer::Drawing_Renderer* renderer,
                       std::vector<DrawingElement::Position> vertices,
                       DrawingElement::Color color);

        // Destructor
        ~FilledPolygonDrawing();

        // Renders line to screen
        bool render() override;

    };

} // namespace Drawing
#endif
