/** ui.cpp
 * 
 */

#include "ui.h"

#include <memory>
#include <vector>

#include "ui_element.h"

/** Constructor
 * 
 */
UI::UI()
{}

/** Destructor
 * 
 */
UI::~UI()
{}

/** public function: add_ui_element()
 * 
 */
void UI::add_ui_element(std::unique_ptr<UIElement> element)
{
    _ui_elements.emplace_back(std::move(element));
}

/** public function:: render()
 * 
 */
void UI::render()
{

}
