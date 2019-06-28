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
        DrawingElement(renderer, Color{r, g, b, alpha})
    {
        // Populate vector of vertices
        for(int i = 0; i < n; i++)
        {
            _vertices.push_back(Position{vx[i], vy[i]});
        }
        
        // Determine min and max coordinates
        _calculate_min_max();
     }

    /** Constructor
     *    @renderer: Pointer to object handling screen output. 
     *    @vertices: coodinates of vertices
     *    @r, @g, @b, @alpha: Color and alpha transparency values.
     */
    PolygonDrawing::PolygonDrawing(
            MediaLayer::Drawing_Renderer* renderer,
            std::vector<Position> vertices,
            Color color):
        DrawingElement(renderer, color),
        _vertices(vertices)
    {
        _calculate_min_max();
    }

    /** Destructor
     */
    PolygonDrawing::~PolygonDrawing()
    {
    }

    /** Public function: render()
     * Renders polygon to screen
     */
    bool PolygonDrawing::render(int x, int y, double rotation)
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
        _vertices.push_back(Position{x, y});
        _calculate_min_max();
    }

    /** public function: vertices()
     * Vertices
     */
    std::vector<Position> PolygonDrawing::vertices()
    {
        return _vertices;
    }

    /** public function: width()
     * Width of the element
     */
    int PolygonDrawing::width()
    {
        return _max_x - _min_x;
    }

    /** public function: height()
     * Height of the element
     */
    int PolygonDrawing::height()
    {
        return _max_y - _min_y;
    }

    /** public function: set_center()
     * Specify the center of the polygon
     */
    void PolygonDrawing::set_center(int x, int y)
    {
        _center = Position{x, y};
    }
    
    /** public function: center()
     * Position of the center of element.
     */
    Position PolygonDrawing::center()
    {
        // Since it's not necessarily a regular polygon, it may be better to specify the center.
        return _center;
    }

    /** private function: min_x()
     * Get the minimum x-coordinate of vertices
     */
    int PolygonDrawing::min_x()
    {
        return _min_x;
    }
    
    /** private function: max_x()
     * Get the maximum x-coordinate of vertices
     */
    int PolygonDrawing::max_x()
    {
        return _max_x;
    }

    /** private function: min_y()
     * Get the minimum x-coordinate of vertices
     */
    int PolygonDrawing::min_y()
    {
        return _min_y;
    }
    
    /** private function: max_y()
     * Get the maximum x-coordinate of vertices
     */
    int PolygonDrawing::max_y()
    {
        return _max_y;
    }
    
    /** public function: min()
     * Position of the upper left corner
     */
    Position PolygonDrawing::min()
    {
        return Position{_min_x, _min_y};
    }

    /** public function: max()
     * Position of the lower right corner
     */
    Position PolygonDrawing::max()
    {
        return Position{_max_x, _max_y};
    }

    /** private function: _calculate_min_max()
     */
    void PolygonDrawing::_calculate_min_max()
    {
        int i = 0;
        int min_x{_vertices[i].x}, max_x{_vertices[i].x};
        int min_y{_vertices[i].y}, max_y{_vertices[i].y};
        Position vertex;
        for(; i < _vertices.size(); ++i)
        {
            vertex = _vertices[i];
            if(vertex.x < min_x)
            {
                min_x = vertex.x;
            }
            if(vertex.x > max_x)
            {
                max_x = vertex.x;
            }
            if(vertex.y < min_y)
            {
                min_y = vertex.y;
            }
            if(vertex.y > max_y)
            {
                max_y = vertex.y;
            }
        }
        _min_x = min_x;
        _max_x = max_x;
        _min_y = min_y;
        _max_y = max_y;        
    }

} // namespace Drawing
