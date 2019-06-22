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
ClockUI::ClockUI(MediaLayer* media_layer,
                 int x, int y,
                 int font_size):
    _media_layer(media_layer),
    _clock_text(media_layer->get_drawing_renderer(),
                "clock",
                "data/lucon.ttf", font_size,
                x, y,
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
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - _start); 
    auto s = std::chrono::duration_cast<std::chrono::seconds>(ms); 
    ms -= std::chrono::duration_cast<std::chrono::milliseconds>(s);
    auto m = std::chrono::duration_cast<std::chrono::minutes>(s); 
    s -= std::chrono::duration_cast<std::chrono::seconds>(m);
    std::string text = std::to_string(m.count()) + ":" + std::to_string(s.count()) + ":" + std::to_string(ms.count());
    _clock_text.update(text);
}

/** public function reset_clock()
 * 
 */
void ClockUI::reset_clock()
{
    _start = std::chrono::system_clock::now();
}

/** private function: now()
 * 
 */
std::chrono::time_point<std::chrono::system_clock> ClockUI::_now()
{
    return std::chrono::system_clock::now();
}

/** private function: duration()
 * 
 */
std::chrono::milliseconds ClockUI::_duration()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(_now() - _start);
}
