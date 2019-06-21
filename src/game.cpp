/** game.cpp
 *
 */

#include <vector>
#include <memory>

#include "game.h"
#include "ui.h"
#include "ui_element_clock.h"
#include "randomnumber.h"
#include "medialayer.h"
#include "drawing_element.h"

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
    initialized = MediaLayer::MediaLayer_Initialize(_game_title, _media_layer, _window_width, _window_height);

    // Initialize Game Objects

    // Initialize UI Objects
    initialized = _ui.initialize();

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
    std::vector<Medialayer_Key_Code> key_codes = MediaLayer::MediaLayer_GetInput(_media_layer);

    // Iterate through inputs and do something
    for(auto key: key_codes)
    {
        // Check for exit
        if(key == Medialayer_Key_Code::quit || key == Medialayer_Key_Code::esc)
        {
            // Exit game
            _is_running = false;
            return;
        } else if(key != Medialayer_Key_Code::null)
        {
            // If key is a valid key, do something (e.g., map key to game action)

        }
    }
}

/** private function: _update_game()
 */
void Game::_update_game()
{

    // Get delta time
    double delta_time = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

    // Update Game Objects

    // Update UI
    _ui.update(delta_time);
}

/** private function: _generate_output()
 */
void Game::_generate_output()
{
    MediaLayer::MediaLayer_GenerateOutput(_media_layer);
}
