/** medialayer_mock.hpp
 * Mock MediaLayer Object
 */

#include <vector>
#include "../../src/medialayer/medialayer.h"

namespace MediaLayer{
    class MediaLayer_Mock: public MediaLayer
    {

    public:

        MediaLayer_Mock(){}
    
        ~MediaLayer_Mock(){}

        // Initializes media layer
        bool initialize()
            {
                return true;
            }

        // Initializes media layer with window dimension, positions window at the center of screen
        bool initialize(std::string title, int window_width, int window_height)
            {
                return true;
            }

        // Initializes media layer with window dimention and position
        bool initialize(std::string title, int window_width, int window_height, int window_x, int window_y)
            {
                return true;
            }

        // Shuts down media layer
        void shutdown()
            {
            }

        // Renders output to screen
        void generate_output()
            {
            }

        // Creates and opens window
        bool create_window()
            {
                return true;
            }

        // Retrieves input from devices
        std::vector<Key_Code> get_input()
            {
                std::vector<Key_Code> codes;
                return codes;
            }

        // Calculates delta time
        double get_delta_time()
            {
                return 0;
            }
    };
}
