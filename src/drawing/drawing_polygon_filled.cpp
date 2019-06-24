/** drawing_polygon_filled.cpp
 *  Class for rendering polygon to screen
 */

#include "drawing_polygon_filled.h"
#include "drawing_polygon.h"
#include <vector>
#include "drawing_element.h"
#include "../medialayer/medialayer_drawing_renderer.h"

namespace Drawing{

    /** Constructor
     *    @renderer: Pointer to object handling screen output.
     *    @vx, @vy: Arrays of int containing x and y-coordinates of vertices
     *    @n: number of vertices
     *    @r, @g, @b, @alpha: Color and alpha transparency values.
     */
    FilledPolygonDrawing::FilledPolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            int* vx, int* vy, int n,
            int r, int g, int b, int alpha):
        PolygonDrawing(renderer, vx, vy, n, r, g, b, alpha)
    {
    }

    /** Constructor
     *    @renderer: Pointer to object handling screen output. 
     *    @vertices: coodinates of vertices
     *    @r, @g, @b, @alpha: Color and alpha transparency values.
     */
    FilledPolygonDrawing::FilledPolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer,
            std::vector<DrawingElement::Position> vertices,
            DrawingElement::Color color):
        PolygonDrawing(renderer, vertices, color)
    {
    }

    /** Destructor
     */
    FilledPolygonDrawing::~FilledPolygonDrawing()
    {
    }

    /** Public function: render()
     * Renders polygon to screen
     */
    bool FilledPolygonDrawing::render()
    {
        int n = _vertices.size();
        short vx[n], vy[n];

        // Populate arrays
        for(int i = 0; i < n; i++)
        {
            vx[i] = static_cast<short>(_vertices[i].x);
            vy[i] = static_cast<short>(_vertices[i].y);
        }
        
        return _drawing_renderer->render_filled_polygon(
                vx, vy, n,
                _color.r, _color.g, _color.b, _color.alpha);
    }

} // namespace Drawing
