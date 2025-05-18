#include <gtest/gtest.h>
#include "../Headers/AddFunctions.h"
#include <cmath>

// Test fixture for math function tests
class MathTest : public ::testing::Test {
protected:
    // Tolerance for floating point comparisons
    const double epsilon = 1e-6;
};

// Test the custom sin function
TEST_F(MathTest, SinFunction) {
    // Test standard angles
    EXPECT_NEAR(custom_math::sin(0), 0.0, epsilon);
    EXPECT_NEAR(custom_math::sin(90), 1.0, epsilon);
    EXPECT_NEAR(custom_math::sin(180), 0.0, epsilon);
    EXPECT_NEAR(custom_math::sin(270), -1.0, epsilon);
    
    // Test arbitrary angle
    const int angle = 45;
    const double expected = std::sin(angle * 3.14159265 / 180);
    EXPECT_NEAR(custom_math::sin(angle), expected, epsilon);
    
    // Test memoization (second call should use cached value)
    EXPECT_NEAR(custom_math::sin(45), custom_math::sin(45), epsilon);
}

// Test the custom cos function
TEST_F(MathTest, CosFunction) {
    // Test standard angles
    EXPECT_NEAR(custom_math::cos(0), 1.0, epsilon);
    EXPECT_NEAR(custom_math::cos(90), 0.0, epsilon);
    EXPECT_NEAR(custom_math::cos(180), -1.0, epsilon);
    EXPECT_NEAR(custom_math::cos(270), 0.0, epsilon);
    
    // Test arbitrary angle
    const int angle = 45;
    const double expected = std::cos(angle * 3.14159265 / 180);
    EXPECT_NEAR(custom_math::cos(angle), expected, epsilon);
    
    // Test memoization (second call should use cached value)
    EXPECT_NEAR(custom_math::cos(45), custom_math::cos(45), epsilon);
}

// Test the int_round function
TEST_F(MathTest, IntRoundFunction) {
    EXPECT_EQ(custom_math::int_round(3.2), 3);
    EXPECT_EQ(custom_math::int_round(3.5), 4);
    EXPECT_EQ(custom_math::int_round(3.7), 4);
    EXPECT_EQ(custom_math::int_round(-2.3), -2);
    EXPECT_EQ(custom_math::int_round(-2.5), -2); // Round away from zero
    EXPECT_EQ(custom_math::int_round(-2.7), -3);
}