/** ui_element_clock.h
 * 
 */

#ifndef UI_ELEMENT_CLOCK_H
#define UI_ELEMENT_CLOCK_H

#include <chrono>
#include "medialayer.h"
#include "ui_element.h"
#include "drawing_text.h"

class ClockUI : public UIElement{
public:

    ClockUI(MediaLayer* media_layer);

    ~ClockUI();

    void update(double delta_time) override;

    void reset_clock();

    std::chrono::time_point<std::chrono::system_clock> now();

    std::chrono::milliseconds duration();

private:

    MediaLayer* _media_layer;
    std::chrono::time_point<std::chrono::system_clock> _start;
    TextDrawing _clock_text;

};
#endif