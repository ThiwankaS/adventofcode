#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

int count_distinguish(std::string& line){
    std::string word;
    std::stringstream ss(line);
    std::unordered_map<std::string, bool> seen;
    while(ss >> word) {
        if(seen.contains(word)) {
            return (0);
        }
        seen.insert({ word, true});
    }
    return (1);
}

int main(void) {

    std::ifstream file("input.txt");
    int total = 0;

    if(!file) {
        std::cerr << "Error : Can not open the file !\n";
    }

    std::string line;
    while(std::getline(file, line)) {
        if(line.empty()) {
            continue;
        }
        total += count_distinguish(line);
    }

    std::cout << "Distinguish passphrase count : " << total << "\n";

    return (EXIT_SUCCESS);
}
