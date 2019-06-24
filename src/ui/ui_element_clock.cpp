/** ui_element_clock.cpp
 * 
 */

#include "ui_element_clock.h"

#include <chrono>
#include <memory>
#include <string>
#include <iomanip>
#include "../medialayer/medialayer.h"
#include "ui_element.h"
#include "../drawing/drawing.h"
#include "../drawing/drawing_element.h"

namespace GameObject{
    namespace UI{

        using namespace std::chrono;

        /** Constructor
         * 
         */
        ClockUI::ClockUI(MediaLayer::MediaLayer* media_layer,
                         int x, int y,
                         int font_size):
            _media_layer(media_layer),
            _clock_text(media_layer->get_drawing_renderer(),
                        "clock",
                        "data/lucon.ttf", font_size,
                        x, y,
                        255, 255, 255, 255)
        {
            _drawing.add_drawing_element(std::unique_ptr<Drawing::DrawingElement>(&_clock_text));
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
            _clock_text.update(_format_duration(_duration()));
        }

        /** public function reset_clock()
         * 
         */
        void ClockUI::reset_clock()
        {
            _start = system_clock::now();
        }

        /** private function: now()
         * 
         */
        time_point<system_clock> ClockUI::_now()
        {
            return system_clock::now();
        }

        /** private function: duration()
         * 
         */
        milliseconds ClockUI::_duration()
        {
            return duration_cast<milliseconds>(_now() - _start);
        }

        /** private function: _format_duration()
         */
        std::string ClockUI::_format_duration(milliseconds ms)
        {
            std::ostringstream ostr;
            char fill = ostr.fill();
            ostr.fill('0');
           
            auto sec = duration_cast<seconds>(ms);
            ms -= sec;
            auto min = duration_cast<minutes>(ms);
            ms -= min;

            ostr << std::setw(2) << min.count() << ":"
                 << std::setw(2) << sec.count() << ":"
                 << std::setw(2) << ms.count();
            ostr.fill(fill);
            return ostr.str();
        }

    } // namespace UI
} // namespace GameObject
