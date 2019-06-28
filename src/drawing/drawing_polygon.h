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
                       std::vector<Position> vertices,
                       Color color);

        // Destructor
        ~PolygonDrawing();

        // Renders line to screen
        bool render(int x = 0, int y = 0, double rotation = 0) override;

        // Add vertice to polygon
        void add_vertice(int x, int y);

        // Vertices
        std::vector<Position> vertices();

        int width() override;

        int height() override;

        Position center() override;

        Position min() override;

        Position max() override;

        void set_center(int x, int y);

        int min_x();

        int max_x();

        int min_y();

        int max_y();

        

    protected:

        std::vector<Position> _vertices;
        Position _center;

        int _min_x, _max_x, _min_y, _max_y;
        

        void _calculate_min_max();

    };

} // namespace Drawing
#endif
