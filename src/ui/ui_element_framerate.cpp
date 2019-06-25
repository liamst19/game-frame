/** ui_element_framerate.cpp
 *
 *  When SDL_Renderer is created with the SDL_RENDERER_PRESENTVSYNC
 *  flag, it locks the frame rate to sync with the monitor's refresh
 *  rate (60fps, for example).
 *  
 */

#include "ui_element_framerate.h"

#include <iostream>
#include <memory>
#include <chrono>
#include <string>
#include "../../include/SDL2/SDL2_framerate.h"
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
        FramerateUI::FramerateUI(
                MediaLayer::MediaLayer* media_layer,
                int x, int y,
                int font_size):
            _media_layer(media_layer),
            _frame_rate{200},
            _start{high_resolution_clock::now()},
            _framerate_text(media_layer->get_drawing_renderer(),
                            "framerate",
                            "data/lucon.ttf", font_size,
                            x, y,
                            255, 255, 255, 255)
        {
            _drawing.add_drawing_element(std::unique_ptr<Drawing::DrawingElement>(&_framerate_text));
            _initialize();
        }

        /** Destructor
         * 
         */
        FramerateUI::~FramerateUI()
        {
        }

        /** public function: set_framerate()
         * Sets Framerate
         *   @framerate: Frame rate in Herz (1 per second)
         */
        void FramerateUI::set_framerate(
                int framerate)
        {
            _frame_rate = framerate;
            SDL_setFramerate(&_fps_manager, static_cast<Uint32>(framerate));
        }

        /** public function: fps()
         * Get current framerate in Herz
         */
        int FramerateUI::fps()
        {
            double fs = _get_duration();
            return static_cast<int>(1 / fs);
        }

        /** public function: framecount()
         * Get frame count
         */
        int FramerateUI::framecount()
        {
            return SDL_getFramecount(&_fps_manager);
        }

        /** private function: _initialize()
         * Initialize SDL2_framerate library
         */
        void FramerateUI::_initialize()
        {
            SDL_initFramerate(&_fps_manager);
            set_framerate(_frame_rate); // 200 is the max framerate
        }

        /** public function update()
         * 
         */
        void FramerateUI::update(
                double delta_time)
        {
            int f = fps();
            _reset_clock();

            _framerate_text.update("FPS:" + std::to_string(f));

            SDL_framerateDelay(&_fps_manager);
        }

        /** private function: _initialize()
         * Initialize SDL2_framerate library
         */
        std::string FramerateUI::_get_fps_text()
        {
            return "FPS:" + std::to_string(fps());
        }

        /** private function: _reset_clock()
         * Reset clock for calculating frame rate
         */
        void FramerateUI::_reset_clock()
        {
            _start = high_resolution_clock::now();
        }

        double FramerateUI::_get_duration()
        {
            return duration_cast<duration<double>>(high_resolution_clock::now() - _start).count();
        }
        
        
    } // namespace UI
} // namespace GameObject
