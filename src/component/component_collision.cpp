/** component_collision.cpp
 */

#include "component_collision.h"
#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        /** Constructor
         */
        CollisionComponent::CollisionComponent(GameObject* game_object):
            Component(game_object)
        {
        }

        /** Destructor
         */
        CollisionComponent::~CollisionComponent()
        {
        }

        /** public function: update()
         * Updates component
         *   @delta_time: delta time
         */
        void CollisionComponent::update(double delta_time)
        {
        }

        /** public function: process_input()
         *
         */
        void CollisionComponent::process_input(std::vector<MediaLayer::Key_Code> key_codes)
        {
        }

        /** public function: render()
         *
         */
        void CollisionComponent::render()
        {
        }

    } // namespace Component
} // namespace GameObject

