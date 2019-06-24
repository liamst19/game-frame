/** drawing_polygon.h
 *  Class for rendering polygon to screen
 */

#ifndef DRAWING_POLYGON_H
#define DRAWING_POLYGON_H

#include <vector>
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    class PolygonDrawing: public DrawingElement
    {

    public:

        // Constructor
        PolygonDrawing(MediaLayer::Drawing_Renderer* renderer, 
                       int* vx, int* vy, int n,
                       int r, int g, int b, int alpha);

        // Constructor
        PolygonDrawing(MediaLayer::Drawing_Renderer* renderer,
                       std::vector<DrawingElement::Position> vertices,
                       DrawingElement::Color color);

        // Destructor
        ~PolygonDrawing();

        // Renders line to screen
        bool render() override;

        // Add vertice to polygon
        void add_vertice(int x, int y);

        // Vertices
        std::vector<DrawingElement::Position> vertices();

    protected:

        std::vector<DrawingElement::Position> _vertices;

    };

} // namespace Drawing
#endif
