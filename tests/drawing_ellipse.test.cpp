/** drawing_ellipse.test.cpp
 * 
 * 
 */

#include "gtest/gtest.h"

#include "../src/drawing/drawing_ellipse.h"
#include "mocks/medialayer_mock_drawing_renderer.hpp"

using namespace Drawing;

namespace {

    MediaLayer::Mock_Drawing_Renderer renderer;
    
    TEST(Drawing_Ellipse_Test, Constructor)
    {
        EllipseDrawing ellipse{&renderer,
                               25, 35,
                               45, 65,
                               1, 2, 3, 4};

        EXPECT_EQ(ellipse.center().x, 25);
        EXPECT_EQ(ellipse.center().y, 35);

        EXPECT_EQ(ellipse.radius_x(), 45);
        EXPECT_EQ(ellipse.radius_y(), 65);

        EXPECT_EQ(ellipse.color().r, 1);
        EXPECT_EQ(ellipse.color().g, 2);
        EXPECT_EQ(ellipse.color().b, 3);
        EXPECT_EQ(ellipse.color().alpha, 4);

        EXPECT_TRUE(ellipse.render());
    }

    TEST(Drawing_Ellipse_Test, Dimensions)
    {
        EllipseDrawing ellipse{&renderer,
                               10, 10,
                               25, 100,
                               0, 0, 0, 0};

        EXPECT_EQ(ellipse.width(), 50);
        EXPECT_EQ(ellipse.height(), 200);
        EXPECT_EQ(ellipse.min().x, -15);
        EXPECT_EQ(ellipse.min().y, -90);
        EXPECT_EQ(ellipse.max().x, 35);
        EXPECT_EQ(ellipse.max().y, 110);
    }

}
