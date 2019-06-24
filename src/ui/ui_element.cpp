/** ui_element.cpp
 * 
 */

#include "ui_element.h"

namespace GameObject{
    namespace UI{

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
    } // namespace UI
} // namespace GameObject
    
