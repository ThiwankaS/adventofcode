#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

/*custome has fucntion*/
struct pair_hash {
    size_t operator()(const std::pair<int, int>& p) const noexcept {
        size_t h1 = std::hash<int>{}(p.first);
        size_t h2 = std::hash<int>{}(p.second);
        return ((h1 ^ h2) << 1);
    }
};

void set_index(
    std::vector<std::pair<int,int>>& data,
    int& number,
    int limit,
    int x,
    int y,
    char p_direction,
    char n_direction,
    int p_size) {

        if(number == limit) {
            return ;
        }
        if(p_direction == 'I' && n_direction == 'R') {
            x++;
            number++;
            data.push_back(std::make_pair(x, y));
            set_index(data, number, limit, x, y, 'R', 'U', 1);
        }
        if(p_direction == 'R' && n_direction == 'U') {
            for(int i = 0; i < p_size && number < limit; i++){
                y++;
                number++;
                data.push_back(std::make_pair(x, y));
            }
            p_size++;
            set_index(data, number, limit, x, y, 'U', 'L', p_size);
        }
        if(p_direction == 'U' && n_direction == 'L') {
            for(int i = 0; i < p_size && number < limit; i++){
                x--;
                number++;
                data.push_back(std::make_pair(x, y));
            }
            set_index(data, number, limit, x, y, 'L', 'D', p_size);
        }
        if(p_direction == 'L' && n_direction == 'D') {
            for(int i = 0; i < p_size && number < limit; i++){
                y--;
                number++;
                data.push_back(std::make_pair(x, y));
            }
            p_size++;
            set_index(data, number, limit, x, y, 'D', 'R', p_size);
        }
        if(p_direction == 'D' && n_direction == 'R') {
            for(int i = 0; i < p_size && number < limit; i++){
                x++;
                number++;
                data.push_back(std::make_pair(x, y));
            }
            set_index(data, number, limit, x, y, 'R', 'U', p_size);
        }
}

std::vector<std::pair<int,int>> calculate_index(int limit) {
    std::vector<std::pair<int,int>>data;
    int x = 0, y = 0, number = 1;
    data.push_back(std::make_pair(x, y));
    set_index(data, number, limit, x, y,'I', 'R', 1);
    return (data);
}

void solution_part_one(std::vector<std::pair<int,int>>& data, const int& limit) {
    int steps_required = std::abs((data[limit - 1].first - data[0].first))
        + std::abs((data[limit - 1].second - data[0].second));

    std::cout << "No of steps required : " << steps_required << "\n";
}

int calculate_value(
    std::unordered_map<std::pair<int,int>,int, pair_hash>& spiral_memory,
    int x,
    int y) {
        // lamda funtion
        auto getValue = [&spiral_memory](int a, int b) -> int {
            if(auto it = spiral_memory.find({a, b}); it != spiral_memory.end()) {
                return (it->second);
            } else {
                return (0);
            }
        };
        return (getValue(x + 1, y) + getValue(x - 1, y) + getValue(x, y + 1) + getValue(x, y - 1)
        + getValue(x - 1, y - 1) + getValue(x - 1, y + 1) + getValue(x + 1, y - 1) + getValue(x + 1, y + 1));
    }

void solution_part_two(std::vector<std::pair<int,int>>& data, const int& limit) {

    int value = 1;
    std::unordered_map<std::pair<int,int>,int, pair_hash> spiral_memory;
    spiral_memory.emplace(std::make_pair(0, 0), value);
    for(size_t i = 1; i < data.size(); i++) {
        int x = data[i].first;
        int y = data[i].second;
        value = calculate_value(spiral_memory, x, y);
        spiral_memory.emplace(std::make_pair(x, y), value);
        if(value > limit){
            break;
        }
    }
    std::cout << "first large value : " << value << "\n";
}

int main(void) {
    int limit;
    std::vector<std::pair<int,int>>data;

    std::cout << "Enter upper limit : ";
    std::cin >> limit;

    data = calculate_index(limit);

    solution_part_one(data, limit);
    solution_part_two(data, limit);

    return(EXIT_SUCCESS);
}
