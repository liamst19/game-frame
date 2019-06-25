/** component_input.cpp
 */

#include "component_input.h"
#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        /** Constructor
         */
        InputComponent::InputComponent(GameObject* game_object):
            Component(game_object)
        {
        }

        /** Destructor
         */
        InputComponent::~InputComponent()
        {
        }

        /** public function: update()
         * Updates component
         *   @delta_time: delta time
         */
        void InputComponent::update(double delta_time)
        {
        }

        /** public function: process_input()
         *
         */
        void InputComponent::process_input(std::vector<MediaLayer::Key_Code> key_codes)
        {
        }

        /** public function: render()
         *
         */
        void InputComponent::render()
        {
        }

    } // namespace Component
} // namespace GameObject

