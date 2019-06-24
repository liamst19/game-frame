/** drawing_rectangle.cpp
 *  Class for rendering polygon to screen
 */

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
    PolygonDrawing::PolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer, 
            int* vx, int* vy, int n,
            int r, int g, int b, int alpha):
        DrawingElement(renderer, DrawingElement::Color{r, g, b, alpha})
    {
        // Populate vector of vertices
        for(int i = 0; i < n; i++)
        {
            add_vertice(vx[i], vy[i]);
        }
     }

    /** Constructor
     *    @renderer: Pointer to object handling screen output. 
     *    @vertices: coodinates of vertices
     *    @r, @g, @b, @alpha: Color and alpha transparency values.
     */
    PolygonDrawing::PolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer,
            std::vector<DrawingElement::Position> vertices,
            DrawingElement::Color color):
        DrawingElement(renderer, color),
        _vertices(vertices)
    {
    }

    /** Destructor
     */
    PolygonDrawing::~PolygonDrawing()
    {
    }

    /** Public function: render()
     * Renders polygon to screen
     */
    bool PolygonDrawing::render()
    {
        int n = _vertices.size();
        short vx[n], vy[n];

        // Populate arrays
        for(int i = 0; i < n; i++)
        {
            vx[i] = static_cast<short>(_vertices[i].x);
            vy[i] = static_cast<short>(_vertices[i].y);
        }
        
        return _drawing_renderer->render_polygon(
                vx, vy, n,
                _color.r, _color.g, _color.b, _color.alpha);
    }

    /** public function: add_vertice()
     * Adds vertice to polygon
     *   @x, @y: coordinates of the vertice
     */
    void PolygonDrawing::add_vertice(
            int x, int y)
    {
        _vertices.push_back(DrawingElement::Position{x, y});
    }

    /** public function: vertices()
     * Vertices
     */
    std::vector<DrawingElement::Position> PolygonDrawing::vertices()
    {
        return _vertices;
    }

} // namespace Drawing
