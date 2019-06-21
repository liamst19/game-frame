/** ui_element_clock.cpp
 * 
 */

#include "ui_element_clock.h"

#include <chrono>
#include <memory>
#include <string>
#include "medialayer.h"
#include "ui_element.h"
#include "drawing.h"
#include "drawing_element.h"

/** Constructor
 * 
 */
ClockUI::ClockUI(MediaLayer* media_layer):
    _media_layer(media_layer),
    _clock_text(media_layer->get_drawing_renderer(),
                "clock",
                "data/lucon.ttf", 16,
                200, 400,
                255, 255, 255, 255)
{
    _drawing.add_drawing_element(std::unique_ptr<DrawingElement>(&_clock_text));
    reset_clock();
}

/** Destructor
 * 
 */
ClockUI::~ClockUI()
{
}

/** public function update()
 * 
 */
void ClockUI::update(double delta_time)
{
    _clock_text.set_text(std::to_string(duration().count()));
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
