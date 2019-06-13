/** drawing.cpp
 * 
 * 
 */

#include <vector>

#include "drawing.h"
#include "drawing_element.h"

/** function: elements
 * 
 */
std::vector<DrawingElement> Drawing::elements()
{
    return _elements;
}

/** function: add_element()
 * 
 */
void Drawing::add_element(DrawingElement element)
{ 
    _elements.push_back(element); 
}

