/** game.cpp
 *
 */

#include <vector>
#include <memory>

#include "game.h"
#include "randomnumber.h"
#include "medialayer.h"
#include "drawing.h"

/* --------------------------------------------------
/* Public

/** function: initialize()
 * 
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

    return initialized;
}

/** function: run_loop()
 * 
 */
void Game::run_loop()
{
    _is_running = true;

    while(_is_running)
    {
        process_input();
        update_game();
        generate_output();
    }

}

/** function: shutdown()
 * 
 */
void Game::shutdown()
{
    if(_media_layer != nullptr)
    {
        MediaLayer::MediaLayer_Shutdown(_media_layer);
        _media_layer = nullptr;
    }
}

/** function: window_width
 * Might refer to Media Layer if window is adjustable
 */
int Game::window_width()
{
    return _window_width;
}

/** function: window_height
 * Might refer to Media Layer if window is adjustable 
 */
int Game::window_height()
{
    return _window_height;
}

/** function: rand()
 * 
 */
int Game::rand(int min, int max)
{
    return _rand.rand(min, max);
}

/* --------------------------------------------------
/* Private

/** function: process_input()
 * 
 */
void Game::process_input()
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

/** function: update_game()
 * 
 */
void Game::update_game()
{

    // Get delta time
    double delta_time = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

    // Update Game Objects

}

/** function: generate_output()
 * 
 */
void Game::generate_output()
{
//    _media_layer->clear_shapes();

//    // Convert and Populate Media Layer with Shapes to be rendered
//   populate_drawings();

    MediaLayer::MediaLayer_GenerateOutput(_media_layer);
 }

// void Game::populate_drawings(){
//     Drawing drawing;

//     drawing.draw_line(10, 10, 10, 50);
//     drawing.draw_line(10, 50, 370, 50);
//     drawing.draw_line(370, 50, 370, 10);
//     drawing.draw_line(370, 10, 10, 10);

//     drawing.draw_line(20, 20, 450, 450, Drawing::Color{150, 0, 200, 0});

//     drawing.draw_circle(500, 250, 100);
//     _media_layer->add_drawing(drawing);
// }