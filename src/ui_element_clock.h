/** ui_element_clock.h
 * 
 */

#ifndef UI_ELEMENT_CLOCK_H
#define UI_ELEMENT_CLOCK_H

#include "ui_element.h"

class ClockUI : public UIElement{
public:

    ClockUI();

    ~ClockUI();

    void update() override;

    void render() override;

private:

};
#endif