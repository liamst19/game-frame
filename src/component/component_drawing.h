/** component_drawing.h
 */

#ifndef COMPONENT_DRAWING_H
#define COMPONENT_DRAWING_H

#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        class DrawingComponent: public Component
        {

        public:

            DrawingComponent(GameObject* game_object);
            
            ~DrawingComponent();

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
