/** math.test.cpp
 * 
 */

#include <cmath>
#include "gtest/gtest.h"
#include "../src/math.h"

namespace{

    TEST(MathTest, Radians){
        EXPECT_FLOAT_EQ(0, Math::ToRadians(0));
        EXPECT_FLOAT_EQ(1.5707963268, Math::ToRadians(90));
        EXPECT_FLOAT_EQ(Math::Pi, Math::ToRadians(180));
        EXPECT_FLOAT_EQ(1.0471975512, Math::ToRadians(60));
    }

    TEST(MathTest, Degrees){
        EXPECT_FLOAT_EQ(0, Math::ToDegrees(0));
        EXPECT_FLOAT_EQ(57.295776, Math::ToDegrees(1));
        EXPECT_FLOAT_EQ(114.5915590262, Math::ToDegrees(2));
        EXPECT_FLOAT_EQ(180, Math::ToDegrees(3.1415926535));
    }

    TEST(MathTest, NearZero){
        EXPECT_TRUE(Math::NearZero(0));
        EXPECT_TRUE(Math::NearZero(0.001));
        EXPECT_FALSE(Math::NearZero(1));
        EXPECT_FALSE(Math::NearZero(0.01));
    }

    TEST(MathTest, SquareRoot){
        EXPECT_FLOAT_EQ(0, Math::Sqrt(0));
        EXPECT_FLOAT_EQ(1, Math::Sqrt(1));
        EXPECT_FLOAT_EQ(2, Math::Sqrt(4));
        EXPECT_FLOAT_EQ(1.4142135624, Math::Sqrt(2));

        // how do I test invalid numbers?
        // EXPECT_FLOAT_EQ(0, Math::Sqrt(-1)); 
    }

    TEST(MathTest, Cosine){
        EXPECT_FLOAT_EQ(1, Math::Cos(0));
        EXPECT_FLOAT_EQ(0.5403023059, Math::Cos(1));
        EXPECT_FLOAT_EQ(-0.4161468365, Math::Cos(2));
        EXPECT_FLOAT_EQ(-1, Math::Cos(Math::Pi));
        EXPECT_FLOAT_EQ(1, Math::Cos(Math::Pi * 2));
        EXPECT_FLOAT_EQ(0.5, Math::Cos(Math::Pi / 3));
    }

    TEST(MathTest, Sine){
        EXPECT_FLOAT_EQ(0, Math::Sin(0));
        EXPECT_NEAR(0, Math::Sin(Math::Pi), 0.000001);
        EXPECT_FLOAT_EQ(1, Math::Sin(Math::Pi / 2));
        EXPECT_FLOAT_EQ(0.8414709848, Math::Sin(1));
        EXPECT_FLOAT_EQ(-0.9589242747, Math::Sin(5));
    }

    TEST(MathTest, Tangent){
        EXPECT_FLOAT_EQ(0, Math::Tan(0));
        EXPECT_NEAR(0, Math::Tan(Math::Pi), 0.000001);
        EXPECT_FLOAT_EQ(1, Math::Tan(Math::Pi / 4));
        EXPECT_FLOAT_EQ(1.5574077247, Math::Tan(1));
        EXPECT_FLOAT_EQ(-2.1850398632, Math::Tan(2));
        EXPECT_FLOAT_EQ(-3.3805150062, Math::Tan(5));
    }

    TEST(MathTest, ArcCosine){
        EXPECT_FLOAT_EQ(1.57079633, Math::Acos(0));
        EXPECT_FLOAT_EQ(0, Math::Acos(1));
        EXPECT_FLOAT_EQ(1.04719755, Math::Acos(0.5));
    }

    TEST(MathTest, ArcSine){
        EXPECT_FLOAT_EQ(0, Math::Asin(0));
        EXPECT_FLOAT_EQ(1.57079633, Math::Asin(1));
        EXPECT_FLOAT_EQ(0.52359878, Math::Asin(0.5));
    }

    TEST(MathTest, ArcTangent2){
        EXPECT_FLOAT_EQ(0.785398163397, Math::Atan2(1, 1));
        EXPECT_FLOAT_EQ(1.107148717794, Math::Atan2(2, 1));
    }

    TEST(MathTest, Cotangent){
        EXPECT_FLOAT_EQ(1, Math::Cot(Math::Pi / 4));
        EXPECT_FLOAT_EQ(0.64209259, Math::Cot(1));
        EXPECT_FLOAT_EQ(2, Math::Cot(0.46364761));
    }

    TEST(MathTest, Slope){
        EXPECT_FLOAT_EQ(0, Math::Slope(1, 0, 0, 0));
        EXPECT_FLOAT_EQ(-1, Math::Slope(2, 1, 1, 2));
        EXPECT_FLOAT_EQ(2, Math::Slope(1, 2, 4, 8));
    }

    TEST(MathTest, LinearY){
        EXPECT_FLOAT_EQ(0, Math::LinearY(0, 0 , 0));
        EXPECT_FLOAT_EQ(2, Math::LinearY(1, 1 , 1));
        EXPECT_FLOAT_EQ(2, Math::LinearY(1, 2 , 0));
        EXPECT_FLOAT_EQ(3, Math::LinearY(0, 0 , 3));
    }

}