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

  // Constructor
  ClockUI(MediaLayer* media_layer,
          int x, int y,
          int font_size);

  // Destructor
  ~ClockUI();

  // Update clock text
  void update(double delta_time) override;

  // Reset Clock
  void reset_clock();

private:

  MediaLayer* _media_layer;
  std::chrono::time_point<std::chrono::system_clock> _start;
  TextDrawing _clock_text;

  std::chrono::time_point<std::chrono::system_clock> _now();

  std::chrono::milliseconds _duration();

};
#endif
