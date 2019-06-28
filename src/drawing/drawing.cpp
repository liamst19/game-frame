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
    }

/** public function:: render()
 * Render Drawing elements
 */
    void Drawing::render()
    {
        for(auto& element: _drawing_elements)
        {
            element->render();
        }
    }

    /** public function: width()
     * Calculates overall width of the drawing
     */
    int Drawing::width()
    {
        int width = 0;

        return width;
    }

    /** public function: height()
     * Calculates overall height of the drawing
     */
    int Drawing::height()
    {
        int height = 0;

        return height;
    }

    /** public function: center()
     * Position of the center of drawing
     */
    Position Drawing::center()
    {
        Position center;

        return center;
    }


} // namespace Drawing
