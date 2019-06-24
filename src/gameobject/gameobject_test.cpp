/** gameobject_test.cpp
 *
 */

#include "gameobject_test.h"

#include <iostream>

#include <memory>
#include <vector>

#include "../game.h"
#include "../medialayer/medialayer.h"

#include "../drawing/drawing.h"
#include "../drawing/drawing_ellipse.h"
#include "../drawing/drawing_polygon_filled.h"
#include "../drawing/drawing_text.h"

namespace GameObject{
    
    TestGameObject::TestGameObject(Game* game):
        GameObject(game)
    {
        init();
    }

// Destructor
    TestGameObject::~TestGameObject()
    {
    }

// Initialize Game Object
    void TestGameObject::init()
    {
        std::cout << "Initializing Test Game Object" << std:: endl;
  
        // Test: Add Drawing -----------------------------------------
        _drawing.add_drawing_element(
                std::make_unique<Drawing::EllipseDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        200, 200,
                        100, 100,
                        255, 255, 255, 175));
                                                                 
        _drawing.add_drawing_element(
                std::make_unique<Drawing::TextDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        "Asteroids",
                        _font_univers,
                        80,
                        _game->window_width()/2 - 180,
                        _game->window_height()/2 - 50,
                        255, 255, 255, 255));

        int vx[]={400, 500, 430, 350}, vy[]={50, 150, 330, 450};
        int n = 4;
        _drawing.add_drawing_element(
                std::make_unique<Drawing::FilledPolygonDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        vx, vy,
                        n,
                        255, 255, 255, 175));
                                                                 
        // -----------------------------------------------------------
    }

/** public function: process_input
 * Process user input
 *   @input: collection of keyboard input codes
 */
    void TestGameObject::process_input(std::vector<MediaLayer::Key_Code> input)
    {
    }
  
// Update Game Object
    void TestGameObject::update(double delta_time)
    {
    }

// Render Game Object to screen
    void TestGameObject::render()
    {
        _drawing.render();
    }

} // namespace GameObject
