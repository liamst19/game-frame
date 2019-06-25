/** ui_element_clock.h
 * 
 */

#ifndef UI_ELEMENT_FRAMERATE_H
#define UI_ELEMENT_FRAMERATE_H

#include <chrono>
#include <string>
#include "../../include/SDL2/SDL2_framerate.h"
#include "../medialayer/medialayer.h"
#include "ui_element.h"
#include "../drawing/drawing_text.h"

namespace GameObject{
    namespace UI{

        class FramerateUI : public UIElement{
        public:

            // Constructor
            FramerateUI(MediaLayer::MediaLayer* media_layer,
                        int x, int y,
                        int font_size);

            // Destructor
            ~FramerateUI();

            // Update clock text
            void update(double delta_time) override;

            int fps();

            int framecount();

            void set_framerate(int framerate);

        private:

            MediaLayer::MediaLayer* _media_layer;
            FPSmanager _fps_manager;
            int _frame_rate;
            std::chrono::high_resolution_clock::time_point _start;
            
            Drawing::TextDrawing _framerate_text;

            void _initialize();

            std::string _get_fps_text();

            void _reset_clock();

            double _get_duration();

        };

    } // namespace UI
} // namespace GameObject
#endif
