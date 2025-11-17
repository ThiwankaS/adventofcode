#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string getPattern(std::vector<int>& banks) {
    std::string pattern;
    for(size_t i = 0; i < banks.size();i++) {
        pattern = pattern + std::to_string(banks[i]);
        pattern = pattern + ",";
    }
    return (pattern);
}


int main(void) {

    std::vector<int> banks = { 0, 5, 10, 0, 11, 14, 13, 4, 11, 8, 8, 7, 1, 4, 12, 11 };
    //std::vector<int> banks = { 0, 2, 7, 0};
    std::vector<std::string> previous;
    std::string pattern;
    std::vector<std::string>::iterator pos;

    pattern = getPattern(banks);
    previous.push_back(pattern);

    int steps = 0;

    while(true) {
        steps++;
        pattern.clear();
        auto it = std::max_element(banks.begin(), banks.end());
        int value = *it;
        *it = 0;
        do {
            it++;
            if(it == banks.end()) {
                it = banks.begin();
            }
            *it = *it + 1;
            value = value - 1;
        } while (value > 0);
        pattern = getPattern(banks);
        if((pos = std::find(previous.begin(), previous.end(), pattern)) != previous.end()){
            break;
        }
        previous.push_back(pattern);
    }
    int loop_size = std::distance(previous.begin(), pos);
    std::cout << "redistribution cycles : " << steps << "\n";
    std::cout << "loop size : " << previous.size() - loop_size << "\n";
    return(EXIT_SUCCESS);
}
