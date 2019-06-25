/** component_drawing.cpp
 */

#include "component_drawing.h"
#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        /** Constructor
         */
        DrawingComponent::DrawingComponent(GameObject* game_object):
            Component(game_object)
        {
        }

        /** Destructor
         */
        DrawingComponent::~DrawingComponent()
        {
        }

        /** public function: update()
         * Updates component
         *   @delta_time: delta time
         */
        void DrawingComponent::update(double delta_time)
        {
        }

        /** public function: process_input()
         *
         */
        void DrawingComponent::process_input(std::vector<MediaLayer::Key_Code> key_codes)
        {
        }

        /** public function: render()
         *
         */
        void DrawingComponent::render()
        {
        }

    } // namespace Component
} // namespace GameObject

