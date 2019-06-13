/** game.h
 *
 * Game entry point.
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "randomnumber.h"
#include "medialayer.h"

class Game{

public:

    Game(std::string game_title, 
         MediaLayer* media_layer,
         int window_width,
         int window_height):
        _game_title(game_title),
        _media_layer(media_layer),
        _window_width(window_width),
        _window_height(window_height)
    {
    };

    ~Game(){};

    // Initializes Game
    bool initialize();

    // Runs game loop
    void run_loop();

    // Shuts down game
    void shutdown();

    // Get Random integer
    int rand(int min, int max);

    // Window Width
    int window_width();

    // Window Height
    int window_height();

private:

    MediaLayer* _media_layer;

    std::string _game_title;

    RandomNumber _rand;

    bool _is_running; // for checking game loop

    int _window_width{720};
    int _window_height{480};

    // Retrieves and handles keyboard input from media layer
    void process_input();

    // Update game objects
    void update_game();

    // Renders updated game objects
    void generate_output();
};
#endif