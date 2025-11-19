#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

int count_super_unique(std::string& line) {
    std::string word;
    std::stringstream ss(line);
    std::unordered_map<std::string, bool> seen;
    while(ss >> word) {
        std::sort(word.begin(), word.end());
        if(seen.contains(word)) {
            return (0);
        }
        seen.insert({ word, true});
    }
    return (1);
}

int count_distinguish(std::string& line) {
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
    int total_distinguish = 0, total_super_uniqu = 0;

    if(!file) {
        std::cerr << "Error : Can not open the file !\n";
    }

    std::string line;
    while(std::getline(file, line)) {
        if(line.empty()) {
            continue;
        }
        total_distinguish += count_distinguish(line);
        total_super_uniqu += count_super_unique(line);
    }

    std::cout << "Distinguish passphrase count : " << total_distinguish << "\n";
    std::cout << "Super unique passphrase count : " << total_super_uniqu << "\n";

    return (EXIT_SUCCESS);
}
