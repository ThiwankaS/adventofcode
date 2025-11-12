#include <iostream>
#include <vector>

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

int main(void) {
    int limit;
    std::vector<std::pair<int,int>>data;

    std::cout << "Enter upper limit : ";
    std::cin >> limit;

    data = calculate_index(limit);

    int steps_required = std::abs((data[limit - 1].first - data[0].first))
        + std::abs((data[limit - 1].second - data[0].second));

    std::cout << "No of steps required : " << steps_required << "\n";

    return(EXIT_SUCCESS);
}
