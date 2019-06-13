/** main.cpp
 *
 * Program entry point.
 * 
 */

#include <iostream>
#include <string>
#include "medialayer_sdl.h"
#include "game.h"

int main(int argc, char* argv[]){

    std::cout << "Starting Program" << std::endl;

    int return_value = 0;

    // Dimensions of the game window
    const int win_width = 720;
    const int win_height = 480;

    // If I wanted to switch between different media layers, here would probably be the best.
    MediaLayer_SDL media_layer;

    // Create Game Object
    std::string title = "Game Study";
    Game game{title};

    // Initialize
    if(game.initialize(&media_layer)){
        // Run game loop
        game.run_loop();
    } else{
        // Something went wrong
        std::cout << "Something went wrong" << std::endl;
        return_value = 1; 
    }

    // End of game, shut down
    game.shutdown();

    // Exiting
    std::cout << "Exiting Program" << std::endl;

    return return_value;
}
