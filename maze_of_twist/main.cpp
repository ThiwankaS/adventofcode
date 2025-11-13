#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main (void) {
    std::ifstream file("intput.txt");

    if(!file) {
        std::cerr << "Error : could not open the file \n";
        return (EXIT_FAILURE);
    }

    std::string line;
    std::vector<int> instructions;

    while(std::getline(file, line)) {
        if(line.empty()) {
            continue;
        }
        instructions.push_back(std::atoi(line.c_str()));
    }

    int jump = 0;
    int stack_pointer = 0, steps = 0, size = instructions.size();

    while(stack_pointer < size || stack_pointer < 0) {
        jump = instructions[stack_pointer];
        instructions[stack_pointer] = instructions[stack_pointer] + 1;
        if(jump == 0) {
            steps++;
            continue;
        }
        stack_pointer = stack_pointer + jump;
        steps++;
    }

    std::cout << "No of steps : " << steps << "\n";

    return (EXIT_SUCCESS);
}
