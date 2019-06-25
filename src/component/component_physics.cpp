/** component_physics.cpp
 */

#include "component_physics.h"
#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        /** Constructor
         */
        PhysicsComponent::PhysicsComponent(GameObject* game_object):
            Component(game_object)
        {
        }

        /** Destructor
         */
        PhysicsComponent::~PhysicsComponent()
        {
        }

        /** public function: update()
         * Updates component
         *   @delta_time: delta time
         */
        void PhysicsComponent::update(double delta_time)
        {
        }

        /** public function: process_input()
         *
         */
        void PhysicsComponent::process_input(std::vector<MediaLayer::Key_Code> key_codes)
        {
        }

        /** public function: render()
         *
         */
        void PhysicsComponent::render()
        {
        }

    } // namespace Component
} // namespace GameObject

