#pragma once

#include <cstddef>
#include <vector>

/**
 * @brief Calculates the simple moving average over complete windows.
 * @param prices Input prices.
 * @param window Number of prices in one window.
 * @return One average per complete window.
 * @throws std::invalid_argument If window is zero or exceeds prices.size().
 */
std::vector<double> calculate_sma(
    const std::vector<double>& prices,
    std::size_t window);