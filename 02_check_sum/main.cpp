#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void solution_part_one(std::vector<std::vector<int>>& data_grid) {
    int check_sum = 0;
    for(auto row : data_grid) {
        auto [min, max] = std::minmax_element(row.begin(), row.end());
        check_sum += (*max - *min);
    }
    std::cout << "Check sum part one : " << check_sum << "\n";
}

void solution_part_two(std::vector<std::vector<int>>& data_grid) {
    int check_sum = 0;

    auto divisible = [](int a, int b) -> int {
        int big = std::max(a, b);
        int small = std::min(a, b);
        return ((big % small) == 0 ? big / small : 0);
    };

    for(auto& row : data_grid) {
        const size_t len = row.size();
        for(size_t i = 0; i + 1 < len; ++i){
            for(size_t j = i + 1;j < len; ++j) {
                check_sum += divisible(row[i], row[j]);
            }
        }
    }
    std::cout << "Check sum part two : " << check_sum << "\n";
}

int main(void) {
    std::ifstream file("input.txt");

    if(!file) {
        std::cerr << "Error ! File can not be opened, \n";
        return (EXIT_FAILURE);
    }

    int value;
    std::string line;
    std::vector<std::vector<int>> data_grid;

    while(std::getline(file, line)) {
        if(line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::vector<int>row;

        while(ss >> value){
            row.push_back(value);
        }

        if(!row.empty()) {
            data_grid.push_back(std::move(row));
        }
    }

    solution_part_one(data_grid);
    solution_part_two(data_grid);

    return(EXIT_SUCCESS);
}
