/** ui_element.cpp
 * 
 */

#include "ui_element.h"

/** Constructor
 */
UIElement::UIElement()
{}

/** public function: render()
 * Renders UI Element
 */
void UIElement::render()
{
    _drawing.render();
}