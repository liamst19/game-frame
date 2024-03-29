/** gameobject_test.h
 *
 */

#ifndef GAMEOBJECT_TEST_H
#define GAMEOBJECT_TEST_H

#include <string>
#include "../medialayer/medialayer.h"
#include "gameobject.h"
#include "../drawing/drawing.h"

namespace GameObject{
    
    class TestGameObject: public GameObject
    {
    public:

        // Constructor
        TestGameObject(Game* game);

        // Destructor
        ~TestGameObject();

        // Initialize Game Object
        void init() override;
  
        // Process User Input
        void process_input(std::vector<MediaLayer::Key_Code> key_codes);
  
        // Update Game Object
        void update(double delta_time) override;

        // Render Game Object to screen
        void render() override;
  
    private:
        Drawing::Drawing _drawing;

        const std::string _font_univers{"data/Univers-Extended.ttf"};
        const std::string _font_lucon{"data/lucon.ttf"};

    };
} // namespace GameObject
#endif // GAMEOBJECT_TEST_H
