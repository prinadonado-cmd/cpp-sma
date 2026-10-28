#include "sma.hpp"

#include <stdexcept>

std::vector<double> calculate_sma(
    const std::vector<double>& prices,
    std::size_t window)
{
    if (window == 0 || window > prices.size()) {
        throw std::invalid_argument(
            "window must be between 1 and prices.size()");
    }

    std::vector<double> result;
    result.reserve(prices.size() - window + 1);

    for (std::size_t start = 0;
        start <= prices.size() - window;
        ++start) {
        double sum = 0.0;

        for (std::size_t offset = 0; offset < window; ++offset) {
            sum += prices[start + offset];
        }

        result.push_back(sum / static_cast<double>(window));
    }

    return result;
}