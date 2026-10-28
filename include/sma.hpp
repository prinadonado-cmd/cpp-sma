#pragma once

/**
 * @file sma.hpp
 * @brief Public interface for simple moving average calculation.
 */

#include <cstddef>
#include <vector>

 /**
  * @brief Calculates the simple moving average over complete windows.
  * @param prices Input prices. The input is not modified.
  * @param window Number of prices in one window.
  * @return A vector containing prices.size() - window + 1 averages.
  * @throws std::invalid_argument If window is zero or exceeds prices.size().
  * @note Time complexity is O(n * window), where n is prices.size().
  */
std::vector<double> calculate_sma(
    const std::vector<double>& prices,
    std::size_t window);