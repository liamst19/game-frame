/** main.cpp
 *
 * Program entry point.
 * 
 */

#include <iostream>
#include <string>
#include "medialayer_sdl.h"
#include "game.h"

void log_event(std::string msg);

int main(int argc, char* argv[]){

    log_event("Starting Program");

    int return_value = 0;

    // Dimensions of the game window
    const int win_width = 720;
    const int win_height = 480;

    // Game Title
    const std::string game_title = "Game Study";

    // If I wanted to switch between different media layers, here would probably be the best.
    SDL::MediaLayer_SDL media_layer;

    // Create Game Object
    Game game{game_title, 
              &media_layer, 
              win_width, 
              win_height};

    // Initialize
    log_event("Initializing Game");
    if(game.initialize()){
        log_event("Starting Game Loop");
        // Run game loop
        game.run_loop();
    } else{
        // Something went wrong
        log_event("Something went wrong");
        return_value = 1; 
    }

    // End of game, shut down
    log_event("Shutting Down Game");
    game.shutdown();

    log_event("Exiting Game");
    return return_value;
}

void log_event(std::string msg)
{
   std::cout << msg.c_str() << std::endl;
}
