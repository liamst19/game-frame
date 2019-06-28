/** drawing_rectangle.test.cpp
 * 
 * 
 */

#include "gtest/gtest.h"

#include "../src/drawing/drawing_rectangle.h"
#include "mocks/medialayer_mock_drawing_renderer.hpp"

using namespace Drawing;

namespace {

    MediaLayer::Mock_Drawing_Renderer renderer;
    
    TEST(Drawing_Rectangle_Test, Constructor)
    {
        RectangleDrawing rect{&renderer,
                              0, 0,
                              50, 50,
                              1, 2, 3, 4};

        EXPECT_EQ(rect.a().x, 0);
        EXPECT_EQ(rect.a().y, 0);
        EXPECT_EQ(rect.b().x, 50);
        EXPECT_EQ(rect.b().y, 50);

        EXPECT_EQ(rect.color().r, 1);
        EXPECT_EQ(rect.color().g, 2);
        EXPECT_EQ(rect.color().b, 3);
        EXPECT_EQ(rect.color().alpha, 4);

        EXPECT_TRUE(rect.render());
    }

    TEST(Drawing_Rectangle_Test, Dimensions)
    {
       RectangleDrawing rect{&renderer,
                              0, 0,
                              50, 50,
                              1, 2, 3, 4};        

       EXPECT_EQ(rect.width(), 50);
       EXPECT_EQ(rect.height(), 50);
       EXPECT_EQ(rect.center().x, 25);
       EXPECT_EQ(rect.center().y, 25);
    }

}
