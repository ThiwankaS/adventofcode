#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

struct Node {
    std::string prog;
    std::string weight;
    std::vector<std::string> children;
    std::vector<Node*> edges;
};

void print_node(Node* n) {
    std::ostringstream os;
    os << "Name : " << n->prog
        << " | Weight : " << n->weight << " | [ ";
        for(auto it : n->children) {
            os << it << " ";
        }
    os << "]\n";
    std::cout<< os.str();
}

Node* create_node(std::string& line) {
    Node* new_node = new Node();
    std::stringstream ss(line);
        std::string word;
        int count = 0;
        while(ss >> word) {
            count++;
            if(count == 1) {
                new_node->prog = word;
            }
            if(count == 2) {
                new_node->weight = word;
            }
            if(word == "->") {
                continue;
            }
            if(count > 3) {
                new_node->children.push_back(word);
            }
            word.clear();
        }
    return (new_node);
}

// Node* create_tree(std::unordered_map<std::string, Node*>& node_list) {
//     Node* root = nullptr;
//     for(auto it : node_list) {
//         for(auto child : it.second->children) {
//             auto ptr = node_list.find(node_list.begin(), node_list.end(), child);

//         }
//     }
// }

int main(void){
    std::ifstream file("input.txt");
    std::unordered_map<std::string, Node*> node_list;

    if(!file) {
        std::cerr << "Error : can not open file \n";
        return (EXIT_FAILURE);
    }

    std::string line;
    while(getline(file, line)) {
        Node* temp = create_node(line);
        if(temp) {
            node_list.emplace(temp->prog, temp);
        }
        line.clear();
    }

    for(auto it : node_list) {
        print_node(it.second);
    }

    return (EXIT_SUCCESS);
}
