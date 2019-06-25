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
#include "../drawing/drawing_image.h"

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
  
        // Test: Add Drawing -----------------------------

        // Image
        _drawing.add_drawing_element(
                std::make_unique<Drawing::ImageDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        _img_file,
                        200, 20));
        // ------------------------------------------------
        // Ellipse
        _drawing.add_drawing_element(
                std::make_unique<Drawing::EllipseDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        200, 200,
                        100, 100,
                        255, 255, 255, 175));
        // -----------------------------------------------
        // Text
        _drawing.add_drawing_element(
                std::make_unique<Drawing::TextDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        "This is a game test.",
                        _font_univers,
                        60,
                        20,
                        _game->window_height()/2 + 50,
                        255, 255, 255, 255));
        // -----------------------------------------------
        // Polygon
        int vx[]={400, 500, 430, 350}, vy[]={50, 150, 330, 450};
        int n = 4;
        _drawing.add_drawing_element(
                std::make_unique<Drawing::FilledPolygonDrawing>(
                        _game->media_layer()->get_drawing_renderer(),
                        vx, vy,
                        n,
                        55, 255, 55, 75));
        // -----------------------------------------------

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
