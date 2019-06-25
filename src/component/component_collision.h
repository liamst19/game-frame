/** component_collision.h
 */

#ifndef COMPONENT_COLLISION_H
#define COMPONENT_COLLISION_H

#include "component.h"

#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        class CollisionComponent: public Component
        {

        public:

            CollisionComponent(GameObject* game_object);
            
            ~CollisionComponent();

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
