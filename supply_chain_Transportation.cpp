#include <iostream>
#include <vector>
#include <limits>

struct Cell {
    int cost;
    int allocation;
    bool is_done;
};

int main() {
    std::vector<int> supply = {60, 50, 75};
    std::vector<int> demand = {40, 60, 45};
    std::vector<std::vector<int>> costs = {
        {16, 20, 25},
        {18, 24, 20},
        {20, 18, 18}
    };
    std::vector<std::vector<Cell>> matrix(supply.size(), std::vector<Cell>(demand.size()));

    for (size_t i = 0; i < supply.size(); ++i) {
        for (size_t j = 0; j < demand.size(); ++j) {
            matrix[i][j] = {costs[i][j], 0, false};
        }
    }

    int step_counter = 0;
    while (true) {
        int min_cost = std::numeric_limits<int>::max();
        size_t min_i = 0, min_j = 0;
        for (size_t i = 0; i < supply.size(); ++i) {
            for (size_t j = 0; j < demand.size(); ++j) {
                if (!matrix[i][j].is_done && matrix[i][j].cost < min_cost) {
                    min_cost = matrix[i][j].cost;
                    min_i = i;
                    min_j = j;
                }
            }
        }
        if (min_cost == std::numeric_limits<int>::max()) {
            break;
        }

        int allocation = std::min(supply[min_i], demand[min_j]);
        matrix[min_i][min_j].allocation = allocation;
        matrix[min_i][min_j].is_done = true;
        supply[min_i] -= allocation;
        demand[min_j] -= allocation;

        std::cout << "Step " << ++step_counter << ":" << std::endl;
        for (size_t i = 0; i < supply.size(); ++i) {
            for (size_t j = 0; j < demand.size(); ++j) {
                std::cout << "(" << matrix[i][j].cost << ", " << matrix[i][j].allocation << ") ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int total_cost = 0;
    for (size_t i = 0; i < supply.size(); ++i) {
        for (size_t j = 0; j < demand.size(); ++j) {
            total_cost += matrix[i][j].cost * matrix[i][j].allocation;
        }
    }

    std::cout << "Minimum transportation cost: " << total_cost << std::endl;

    return 0;
}
