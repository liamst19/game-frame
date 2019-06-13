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
        Game game{"Game Test"};

        ASSERT_FALSE(game.initialize());
    }


}