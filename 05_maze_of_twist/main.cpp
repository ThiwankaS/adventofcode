#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void solution_part_one(std::vector<int> instructions) {
    int jump = 0;
    int stack_pointer = 0, steps = 0, size = instructions.size();

    while(stack_pointer < size) {
        jump = instructions[stack_pointer];
        instructions[stack_pointer] = instructions[stack_pointer] + 1;
        if(jump == 0) {
            steps++;
            continue;
        }
        stack_pointer = stack_pointer + jump;
        steps++;
    }

    std::cout << "No of steps (normal jump) : " << steps << "\n";
}

void solution_part_two(std::vector<int> instructions) {
    int jump = 0;
    int stack_pointer = 0, steps = 0, size = instructions.size();

    while(stack_pointer < size) {
        jump = instructions[stack_pointer];
        if(jump >= 3) {
            instructions[stack_pointer] = instructions[stack_pointer] - 1;
        } else {
            instructions[stack_pointer] = instructions[stack_pointer] + 1;
        }
        stack_pointer = stack_pointer + jump;
        steps++;
    }
     std::cout << "No of steps (wired jump) : " << steps << "\n";
}

int main (void) {
    std::ifstream file("input.txt");

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
    solution_part_one(instructions);
    solution_part_two(instructions);
    return (EXIT_SUCCESS);
}
