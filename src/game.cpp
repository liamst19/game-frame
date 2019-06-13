/** game.cpp
 *
 */

#include <vector>

#include "game.h"
#include "randomnumber.h"
#include "medialayer.h"

/* --------------------------------------------------
/* Public

/** function: initialize()
 * 
 */
bool Game::initialize(){

    if(_media_layer == nullptr){
        // throw exception: media layer is not initialized
        return false;
    } else if(_window_width <= 0 || _window_height <= 0){
        // throw exception: invalid window size
        return false;
    }

    bool initialized = true;

    // Initialize Media Layer
    initialized = MediaLayer::MediaLayer_Initialize(_title, _media_layer, _window_width, _window_height);

    // Initialize Game Objects

    return initialized;
}

/** function: initialize()
 * 
 */
bool Game::initialize(MediaLayer* media_layer){

    _media_layer = media_layer;

    return initialize();
}

/** function: initialize()
 * 
 */
bool Game::initialize(MediaLayer* media_layer, int window_width, int window_height){

    _window_width = window_width;
    _window_height = window_height; 

    return initialize(media_layer);
}

/** function: run_loop()
 * 
 */
void Game::run_loop(){
    _is_running = true;

    while(_is_running){
        process_input();
        update_game();
        generate_output();
    }

}

/** function: shutdown()
 * 
 */
void Game::shutdown(){
    if(_media_layer != nullptr){
        MediaLayer::MediaLayer_Shutdown(_media_layer);
    }
}

/* --------------------------------------------------
/* Private

/** function: process_input()
 * 
 */
void Game::process_input(){

    // Get Device Inputs
    std::vector<Medialayer_Key_Code> key_codes = MediaLayer::MediaLayer_GetInput(_media_layer);

    // Iterate through inputs and do something
    for(auto key: key_codes){
    
        // Check for exit
        if(key == Medialayer_Key_Code::quit || key == Medialayer_Key_Code::esc){
            // Exit game
            _is_running = false;
            return;
        } else if(key != Medialayer_Key_Code::null){
            // If key is a valid key, do something (e.g., map key to game action)

        }
    }
}

/** function: update_game()
 * 
 */
void Game::update_game(){

    // Get delta time
    double delta_time = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

    // Update Game Objects

}

/** function: generate_output()
 * 
 */
void Game::generate_output(){
    _media_layer->clear_shapes();

    // Convert and Populate Media Layer with Shapes to be rendered
    

    MediaLayer::MediaLayer_GenerateOutput(_media_layer);
 }

/** function: rand()
 * 
 */
int Game::rand(int min, int max){
    return _rand.rand(min, max);
}