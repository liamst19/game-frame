/** medialayer.h
 *
 * Interface for receiving input from devices, 
 * and sending output to screen. Probably completely
 * unnecessary and perhaps a waste of time.
 * 
 */
#ifndef MEDIALAYER_H
#define MEDIALAYER_H

#include <vector>
#include <string>
#include "medialayer_drawing_renderer.h"

class Game;

namespace MediaLayer{
  

// Keyboard inputs and window events
enum class Key_Code{
  null=0, // default
  quit,
  esc,
  spc,
  w,
  a,
  s,
  d,
  semicolon
};

class MediaLayer{

public:

  MediaLayer(int window_width = 0,
             int window_height = 0,
             int window_x = 0,
             int window_y = 0):
    _window_width(window_width),
    _window_height(window_height),
    _win_coordinate_x(window_x),
    _win_coordinate_y(window_y){};
  
  virtual ~MediaLayer(){};

  // --------------------------------------------------

  // Initializes media layer
  virtual bool initialize(Game* game) =0;

  // Initializes media layer with window dimension, positions window at the center of screen
  virtual bool initialize(Game* game, std::string title, int window_width, int window_height) =0;

  // Initializes media layer with window dimention and position
  virtual bool initialize(Game* game, std::string title, int window_width, int window_height, int window_x, int window_y) =0;

  // Shuts down media layer
  virtual void shutdown() =0;

  // Renders output to screen
  virtual void generate_output() =0;

  // Creates and opens window
  virtual bool create_window() =0;

  // Retrieves input from devices
  virtual std::vector<Key_Code> get_input() =0;

  // Calculates delta time
  virtual double get_delta_time() =0;

  // Get pointer to drawing renderer
  virtual Drawing_Renderer* get_drawing_renderer() =0;

  // --------------------------------------------------

  // Window Width
  int window_width();

  // Window Height
  int window_height();

protected:

  Game* _game;
  std::string _title;
  int _window_width, _window_height;          // Window size
  int _win_coordinate_x, _win_coordinate_y;   // Coordinate where the window will be created

  int _ticks_count{0};                // For calculating delta time
  const int _ms_per_frame{16};        // For delta time: 60fps = apprx. 1 frame per 16ms
  const double _delta_max{0.05};      // Cap for delta time, in seconds

private:

};

} // namespace Media
#endif
