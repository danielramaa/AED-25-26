#include <iostream>
#include <string>
#include <algorithm>

int main() {

    int n;
    int s;
    int i_count;
    std::cin >> n >> s >> i_count;

    std::string chests;
    std::cin >> chests;

    int current_pos = s;
    int min_pos = s;
    int max_pos = s;

    for (int i = 0; i < i_count; ++i) {
        char direction;
        int steps;
        std::cin >> direction >> steps;

        if (direction == 'R') {
            current_pos += steps;
        } else {
            current_pos -= steps;
        }

        min_pos = std::min(min_pos, current_pos);
        max_pos = std::max(max_pos, current_pos);
    }

    int treasure_count = 0;
    for (int pos = min_pos; pos <= max_pos; ++pos) {
        if (chests[pos - 1] == 'T') {
            treasure_count++;
        }
    }

    std::cout << treasure_count << std::endl;

    return 0;
}