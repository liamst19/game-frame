/** component_input.h
 */

#ifndef COMPONENT_INPUT_H
#define COMPONENT_INPUT_H

#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        class InputComponent: public Component
        {

        public:

            InputComponent(GameObject* game_object);
            
            ~InputComponent();

            // Process Update
            void update(double delta_time) override;

            // Process User Input
            void process_input(std::vector<MediaLayer::Key_Code> key_codes) override;

            // Render to screen
            void render() override;
            
        };

    } // namespace Component
} // namespace GameObject
#endif
