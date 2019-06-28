/** drawing.cpp
 * 
 */

#include "drawing.h"

#include <memory>
#include <vector>

#include "drawing_element.h"

namespace Drawing{
    
/** Constructor
 */
    Drawing::Drawing()
    {}

/** Destructor
 */
    Drawing::~Drawing()
    {}

/** public function: add_drawing_element()
 * Adds Drawing element
 *   @elmeent: Drawing element object
 */
    void Drawing::add_drawing_element(std::unique_ptr<DrawingElement> element)
    {
        _drawing_elements.emplace_back(std::move(element));
        _find_min_max();
    }
    
/** public function:: render()
 * Render Drawing elements
 */
    void Drawing::render(int x, int y, double rotation)
    {
        for(auto& element: _drawing_elements)
        {
            element->render(x, y, rotation);
        }
    }

    /** public function: width()
     * Calculates overall width of the drawing
     */
    int Drawing::width()
    {
        return _max.x - _min.x;
    }

    /** public function: height()
     * Calculates overall height of the drawing
     */
    int Drawing::height()
    {
        return _max.y - _min.y;
    }

    Position Drawing::min()
    {
        return _min;
    }

    Position Drawing::max()
    {
        return _max;
    }

    void Drawing::_find_min_max()
    {
        int min_x, min_y, max_x, max_y;
        int i = 0;
        Position min_p = _drawing_elements[i].get()->min();
        Position max_p = _drawing_elements[i].get()->max();

        min_x = max_x = min_p.x;
        min_y = max_y = max_p.y;
        
        for(;i < _drawing_elements.size(); ++i)
        {
            min_p = _drawing_elements[i].get()->max();
            max_p = _drawing_elements[i].get()->max();

            // Get Min coordinates
            if(min_p.x < min_x)
            {
                min_x = min_p.x;
            }

            if(min_p.y < min_y)
            {
                min_y = min_p.y;
            }

            // Get Max coordinates
            if(max_p.x > max_x)
            {
                max_x = max_p.x;
            }

            if(max_p.y > max_y)
            {
                max_y = max_p.y;
            }
        }
        _min = Position{min_x, min_y};
        _max = Position{max_x, max_y};
    }

    /** public function: center()
     * Position of the center of drawing
     */
    Position Drawing::center()
    {
        return Position{_min.x + (width() / 2), _min.y + (height() / 2)};
    }

    void Drawing::set_position(Position position)
    {
        _position = position;
    }

    void Drawing::move(int x, int y)
    {
        _position.x += x;
        _position.y += y;
    }


} // namespace Drawing
