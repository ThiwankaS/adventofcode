#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main(void) {
    std::ifstream file("input.txt");

    if(!file) {
        std::cerr << "Error ! File can not be opened, \n";
        return (EXIT_FAILURE);
    }

    int value, check_sum = 0;
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

    for(auto row : data_grid) {
        auto [min, max] = std::minmax_element(row.begin(), row.end());
        check_sum += (*max - *min);
    }

    std::cout << "Check sum : " << check_sum << "\n";
    return(EXIT_SUCCESS);
}
