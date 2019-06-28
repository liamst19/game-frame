/** drawing_polygon.test.cpp
 * 
 * 
 */

#include <vector>
#include "gtest/gtest.h"
#include "mocks/medialayer_mock_drawing_renderer.hpp"

#include "../src/drawing/drawing_polygon.h"
#include "../src/drawing/drawing.h"

using namespace Drawing;

namespace {

    MediaLayer::Mock_Drawing_Renderer renderer;
    
    TEST(Drawing_Polygon_Test, Constructor_Vector)
    {
        std::vector<Position> vertices;
        vertices.push_back(Position{10, 5});
        vertices.push_back(Position{25, 125});
        vertices.push_back(Position{15, 100});

        Color color{1, 2, 3, 4};
        
        PolygonDrawing poly{&renderer, vertices, color};
        poly.set_center(55, 65);

        EXPECT_EQ(poly.center().x, 55);
        EXPECT_EQ(poly.center().y, 65);
        
        EXPECT_EQ(poly.width(), 15);
        EXPECT_EQ(poly.height(), 120);

        EXPECT_EQ(poly.max_x(), 25);
        EXPECT_EQ(poly.min_x(), 10);
        EXPECT_EQ(poly.max_y(), 125);
        EXPECT_EQ(poly.min_y(), 5);

        EXPECT_EQ(poly.color().r, 1);
        EXPECT_EQ(poly.color().g, 2);
        EXPECT_EQ(poly.color().b, 3);
        EXPECT_EQ(poly.color().alpha, 4);

        EXPECT_TRUE(poly.render());
    }

    TEST(Drawing_Polygon_Test, Constructor_Array)
    {
        int x[] = {10, 25};
        int y[] = {5, 125};
        
        PolygonDrawing poly{&renderer,
                            x, y, 2,
                            1, 2, 3, 4};
        poly.set_center(55, 65);
        poly.add_vertice(15, 100);

        EXPECT_EQ(poly.center().x, 55);
        EXPECT_EQ(poly.center().y, 65);

        EXPECT_EQ(poly.width(), 15);
        EXPECT_EQ(poly.height(), 120);

        EXPECT_EQ(poly.max_x(), 25);
        EXPECT_EQ(poly.min_x(), 10);
        EXPECT_EQ(poly.max_y(), 125);
        EXPECT_EQ(poly.min_y(), 5);

        EXPECT_EQ(poly.color().r, 1);
        EXPECT_EQ(poly.color().g, 2);
        EXPECT_EQ(poly.color().b, 3);
        EXPECT_EQ(poly.color().alpha, 4);

        EXPECT_TRUE(poly.render());
    }
    
    TEST(Drawing_Polygon_Test, MinMaxCenter)
    {
        std::vector<Position> vertices;
        vertices.push_back(Position{10, 5});
        vertices.push_back(Position{25, 125});
        vertices.push_back(Position{15, 100});

        Color color{1, 2, 3, 4};
        
        PolygonDrawing poly{&renderer, vertices, color};
        poly.set_center(55, 65);

        ASSERT_EQ(10, poly.min().x);
        ASSERT_EQ(5, poly.min().y);
        ASSERT_EQ(25, poly.max().x);
        ASSERT_EQ(125, poly.max().y);
        ASSERT_EQ(55, poly.center().x);
        ASSERT_EQ(65, poly.center().y);
    };

}
