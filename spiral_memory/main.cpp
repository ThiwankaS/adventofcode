#include <iostream>
#include <vector>



void set_index(
    std::vector<std::pair<int,int>>& data,
    int& number,
    int limit,
    int right,
    int left,
    int up,
    int down,
    char p_direction,
    int p_size) {

        if(number == limit){
            return ;
        }
        if(p_direction == 'R') {
            for(int i = 0; i < p_size && number < limit; i++) {
                number++;
                data.push_back(std::make_pair(right - left + i, up - down));
            }
            right++;
            set_index(data, number, limit, right, left, up, down, 'U', p_size);
        }
        if(p_direction == 'U') {
            for(int i = 0; i < p_size && number < limit; i++) {
                number++;
                data.push_back(std::make_pair(right - left, up - down + i));
            }
            up++;
            set_index(data, number, limit, right, left, up, down, 'L', p_size + 1);
        }
        if(p_direction == 'L') {
            for(int i = 0; i <= p_size && number < limit; i++) {
                number++;
                data.push_back(std::make_pair(right - left - i, up - down));
            }
            left++;
            set_index(data, number, limit, right, left, up, down, 'D', p_size);
        }
        if(p_direction == 'D') {
            for(int i = 0; i < p_size && number < limit; i++) {
                number++;
                data.push_back(std::make_pair(right - left, up - down - i));
            }
            down++;
            set_index(data, number, limit, right, left, up, down, 'R', p_size + 1);
        }
}

std::vector<std::pair<int,int>> calculate_index(int limit) {
    std::vector<std::pair<int,int>>data;
    int right = 0, left = 0, up = 0, down = 0, number = 1;
    set_index(data, number, limit, right, left, up, down, 'R', 1);
    return (data);
}

int main(void) {
    int limit;
    std::vector<std::pair<int,int>>data;

    std::cout << "Enter upper limit : ";
    std::cin >> limit;

    data = calculate_index(limit);

    int i = 1;
    for(auto it : data) {
        std::cout << "data ["
            << i << "] : ("
            << it.first << ", "
            << it.second << ") \n";
        i++;
    }

    return(EXIT_SUCCESS);
}
