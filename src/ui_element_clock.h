/** ui_element_clock.h
 * 
 */

#ifndef UI_ELEMENT_CLOCK_H
#define UI_ELEMENT_CLOCK_H

#include <chrono>
#include "ui_element.h"

class ClockUI : public UIElement{
public:

    ClockUI();

    ~ClockUI();

    void update() override;

    void render() override;

    void reset_clock();

    std::chrono::time_point<std::chrono::system_clock> now();

    std::chrono::milliseconds duration();



private:

    std::chrono::time_point<std::chrono::system_clock> _start;

};
#endif