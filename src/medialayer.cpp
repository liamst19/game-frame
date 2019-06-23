/** medialayer.cpp
 *
 */

#include <vector>
#include <string>
#include "medialayer.h"
#include "game.h"

/** function: window_width()
 */
int MediaLayer::window_width()
{
  return _window_width;
}

/** function: window_height()
 */
int MediaLayer::window_height()
{
  return _window_height;
}

// ----------------------------------------------------------------------

/** function: MediaLayer_Initialize()
 */
bool MediaLayer::MediaLayer_Initialize(Game* game,
                                       std::string title,
                                       MediaLayer* layer,
                                       int window_width,
                                       int window_height)
{
  return layer->initialize(game, title, window_width, window_height);
}

/** function: MediaLayer_Shutdown()
 */
void MediaLayer::MediaLayer_Shutdown(MediaLayer* layer)
{
  layer->shutdown();
}

/** function: MediaLayer_GetInput()
 */
std::vector<MediaLayer_Key_Code> MediaLayer::MediaLayer_GetInput(MediaLayer* layer)
{
  return layer->get_input();
}

/** function: MediaLayer_GenerateOutput()
 */
void MediaLayer::MediaLayer_GenerateOutput(MediaLayer* layer)
{
  layer->generate_output();
}

/** function MediaLayer_GetDeltaTime()
 */
double MediaLayer::MediaLayer_GetDeltaTime(MediaLayer* layer)
{
  return layer->get_delta_time();
}
