/** gameobject_test.cpp
 *
 */

#include "gameobject_test.h"

#include <iostream>

#include <memory>
#include <vector>

#include "game.h"
#include "medialayer.h"
#include "gameobject.h"

#include "drawing.h"
#include "drawing_ellipse.h"
#include "drawing_text.h"

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
    _drawing.add_drawing_element(std::make_unique<EllipseDrawing>(
                                _game->media_layer()->get_drawing_renderer(),
                                200, 200,
                                100, 100,
                                255, 255, 255, 255,
                                false));
                                                                 
    _drawing.add_drawing_element(std::make_unique<TextDrawing>(
                                _game->media_layer()->get_drawing_renderer(),
                                "Asteroids",
                                _font_univers,
                                80,
                                _game->window_width()/2 - 180,
                                _game->window_height()/2 - 50,
                                255, 255, 255, 255));
    // -----------------------------------------------------------
}

/** public function: process_input
 * Process user input
 *   @input: collection of keyboard input codes
 */
void TestGameObject::process_input(std::vector<MediaLayer_Key_Code> input)
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
