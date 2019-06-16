/** drawing.test.cpp
 * 
 */

#include <vector>
#include "gtest/gtest.h"
#include "../src/drawing_point.h"
#include "../src/drawing.h"

namespace
{

    TEST(Drawing_Point, Constructor_Ints)
    {
        PointDrawing point{0, 0, 0, 0, 0, 0};
        
        ASSERT_EQ(0, point.x());
        ASSERT_EQ(0, point.y());
        ASSERT_EQ(0, point.color().r);
        ASSERT_EQ(0, point.color().g);
        ASSERT_EQ(0, point.color().b);
        ASSERT_EQ(0, point.color().alpha);
    };
    
    TEST(Drawing_Point, Constructor_Structs)
    {
        Drawing::Point crd{29, 57};
        Drawing::Color color{1, 2, 3, 4};
        PointDrawing point{crd, color};

        ASSERT_EQ(29, point.x());
        ASSERT_EQ(57, point.y());
        ASSERT_EQ(1, point.color().r);
        ASSERT_EQ(2, point.color().g);
        ASSERT_EQ(3, point.color().b);
        ASSERT_EQ(4, point.color().alpha);
    };

    TEST(Drawing_Point, Render)
    {
        PointDrawing point(Drawing::Point{100, 100}, Drawing::Color{256, 256, 256, 0});
        ASSERT_TRUE(point.render());   
    }


}