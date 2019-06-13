/** game.test.cpp
 * 
 * 
 */

#include <cmath>

#include "gtest/gtest.h"

#include "../src/game.h"
#include "../src/medialayer.h"
#include "../src/medialayer_sdl.h"

namespace {

    // Default Constructor
    TEST(GameTest, DefaultConstructor){
        Game game{"Game Test", nullptr, 125, 360};

        ASSERT_FALSE(game.initialize());
        ASSERT_EQ(125, game.window_width());
        ASSERT_EQ(360, game.window_height());
    }


}