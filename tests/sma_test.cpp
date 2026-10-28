#include "sma.hpp"

#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

TEST(Sma, CalculatesMovingAverage)
{
    const auto result = calculate_sma({ 10.0, 20.0, 30.0, 40.0 }, 3);

    ASSERT_EQ(result.size(), 2u);
    EXPECT_DOUBLE_EQ(result[0], 20.0);
    EXPECT_DOUBLE_EQ(result[1], 30.0);
}

TEST(Sma, WindowOneKeepsPrices)
{
    const auto result = calculate_sma({ 1.5, 2.5, 3.5 }, 1);

    ASSERT_EQ(result.size(), 3u);
    EXPECT_DOUBLE_EQ(result[0], 1.5);
    EXPECT_DOUBLE_EQ(result[1], 2.5);
    EXPECT_DOUBLE_EQ(result[2], 3.5);
}

TEST(Sma, WindowEqualToInputSize)
{
    const auto result = calculate_sma({ 10.0, 20.0, 30.0, 40.0 }, 4);

    ASSERT_EQ(result.size(), 1u);
    EXPECT_DOUBLE_EQ(result[0], 25.0);
}

TEST(Sma, HandlesFractionalPrices)
{
    const auto result = calculate_sma({ 0.1, 0.2, 0.3 }, 2);

    ASSERT_EQ(result.size(), 2u);
    EXPECT_NEAR(result[0], 0.15, 1e-12);
    EXPECT_NEAR(result[1], 0.25, 1e-12);
}

TEST(Sma, RejectsInvalidInput)
{
    EXPECT_THROW(
        calculate_sma({ 10.0, 20.0 }, 0),
        std::invalid_argument);

    EXPECT_THROW(
        calculate_sma({ 10.0, 20.0 }, 3),
        std::invalid_argument);

    EXPECT_THROW(
        calculate_sma({}, 1),
        std::invalid_argument);
}