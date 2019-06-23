/** game.cpp
 * Game Engine
 */

#include <vector>
#include <memory>

#include "game.h"
#include "ui.h"
#include "ui_element_clock.h"
#include "randomnumber.h"
#include "medialayer.h"
#include "drawing_element.h"
#include "drawing_text.h"
#include "drawing_ellipse.h"

#include "gameobject.h"
#include "gameobject_test.h"

// -------------------------------------------------------------
// Tests -------------------------------------------------------
void Game::_test_init()
{
    // Test: Add GameObject---------------------------------------
    add_game_object(std::make_unique<TestGameObject>(this));
    // -----------------------------------------------------------
    // Test: Add Clock UI Element --------------------------------
    _ui.add_ui_element(std::make_unique<ClockUI>(_media_layer, 2, 2, 12));
    // -----------------------------------------------------------
}

void Game::_test_update(double delta_time)
{
}

void Game::_test_output()
{
}

/* --------------------------------------------------
/* Public

/** public function: initialize()
 *  Initializes the game, readying game input/output
 */
bool Game::initialize()
{
    // Check if Media Layer exists
    if(_media_layer == nullptr)
    {
        // throw exception: media layer is not initialized
        return false;
    } else if(_window_width <= 0 || _window_height <= 0)
    {
        // throw exception: invalid window size
        return false;
    }

    bool initialized = true;

    // Initialize Media Layer
    initialized = MediaLayer::MediaLayer_Initialize(
                                  this,
                                  _game_title,
                                  _media_layer,
                                  _window_width,
                                  _window_height);

    // Initialize Game Objects

    // Initialize UI Objects
    add_game_object(std::unique_ptr<GameUI>(&_ui));

    // Test ------------------------------------------------------
    _test_init();
    // -----------------------------------------------------------

    return initialized;
}

/** public function: run_loop()
 *  Begins game loop.
 */
void Game::run_loop()
{
    _is_running = true;

    while(_is_running)
    {
        _process_input();
        _update_game();
        _generate_output();
    }

}

/** public function: shutdown()
 *  Frees resources for closing.
 */
void Game::shutdown()
{
    if(_media_layer != nullptr)
    {
        MediaLayer::MediaLayer_Shutdown(_media_layer);
        _media_layer = nullptr;
    }
}

/** public function: add_game_object()
 * Adds game object to game
 *   @game_object: Game Object
 */
void Game::add_game_object(std::unique_ptr<GameObject> game_object)
{
  _game_objects.emplace_back(std::move(game_object));
}

/** public function: render_objects()
 * Renders game and UI objects.  This should be called during
 * MediaLayer's rendering sequence, where screen is cleared and then
 * new image is blitted to screen.
 * 
 */
void Game::render_objects()
{
    // Test --------------------------------------------------
    _test_output();
    // -------------------------------------------------------

    // Render Game Objects
    for(auto& obj: _game_objects)
      {
        obj->render();
      }
}

/** public function: media_layer()
 * Get pointer to media layer
 */
MediaLayer* Game::media_layer()
{
    return _media_layer;
}

/** public function: window_width
 * Might refer to Media Layer if window is adjustable
 */
int Game::window_width()
{
    return _window_width;
}

/** public function: window_height
 * Might refer to Media Layer if window is adjustable 
 */
int Game::window_height()
{
    return _window_height;
}

/** public function: rand()
 *  Returns a random integer between min and max 
 *  values specified.
 */
int Game::rand(int min, int max)
{
    return _rand.rand(min, max);
}

/* --------------------------------------------------
/* Private

/** private function: _process_input()
 *  Listens for keyboard inputs and do something with them.
 */
void Game::_process_input()
{
    // Get Device Inputs
    std::vector<MediaLayer_Key_Code> key_codes = MediaLayer::MediaLayer_GetInput(_media_layer);

    // Iterate through inputs and do something
    for(auto key: key_codes)
    {
        // Check for exit
        if(key == MediaLayer_Key_Code::quit || key == MediaLayer_Key_Code::esc)
        {
            // Exit game
            _is_running = false;
            return;
        } else if(key != MediaLayer_Key_Code::null)
        {
            // If key is a valid key, do something (e.g., map key to game action)

        }
    }

    // Pass events to game objects.
    for(auto& obj: _game_objects)
      {
        obj->process_input(key_codes);
      }

}

/** private function: _update_game()
 */
void Game::_update_game()
{
    // Get delta time
    double delta_time = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

    // Update Game Objects
    // Render Game Objects
    for(auto& obj: _game_objects)
      {
        obj->update(delta_time);
      }

    // Test --------------------------------------------------
    _test_update(delta_time);
    // -------------------------------------------------------
}

/** private function: _generate_output()
 */
void Game::_generate_output()
{
    MediaLayer::MediaLayer_GenerateOutput(_media_layer);
}
