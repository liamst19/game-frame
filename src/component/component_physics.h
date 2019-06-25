/** component_physics.h
 */

#ifndef COMPONENT_PHYSICS_H
#define COMPONENT_PHYSICS_H

#include "component.h"
#include <vector>
#include "../medialayer/medialayer.h"

namespace GameObject{
    namespace Component{

        class PhysicsComponent: public Component
        {

        public:

            PhysicsComponent(GameObject* game_object);
            
            ~PhysicsComponent();

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
