/** medialayer.cpp
 *
 */

#include <vector>
#include <string>
#include "medialayer.h"
#include "../game.h"

namespace MediaLayer{
  
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

} // namespace Media
