#include "sma.hpp"

#include <iostream>
#include <vector>

int main()
{
    const std::vector<double> prices{ 10.0, 20.0, 30.0, 40.0 };
    const auto averages = calculate_sma(prices, 3);

    std::cout << "SMA:";
    for (double value : averages) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';

    return 0;
}