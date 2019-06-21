/** ui_element_clock.cpp
 * 
 */

#include "ui_element_clock.h"

#include <chrono>
#include "ui_element.h"

/** Constructor
 * 
 */
ClockUI::ClockUI()
{
}

/** Destructor
 * 
 */
ClockUI::~ClockUI()
{
}

/** public function render()
 * 
 */
void ClockUI::update()
{
}

/** public function render()
 * 
 */
void ClockUI::render()
{
}

/** public function reset_clock()
 * 
 */
void ClockUI::reset_clock()
{
    _start = std::chrono::system_clock::now();
}

/** public function: now()
 * 
 */
std::chrono::time_point<std::chrono::system_clock> ClockUI::now()
{
    return std::chrono::system_clock::now();
}

/** public function: duration()
 * 
 */
std::chrono::milliseconds ClockUI::duration()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(now() - _start);
}
