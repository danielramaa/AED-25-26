#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int odd_count = 0;
    int last_odd = -1;

    for (int i = 0; i < n; ++i) {
        int current_number;
        std::cin >> current_number;

        if (current_number % 2 != 0) {
            odd_count++;
            last_odd = current_number;
        }
    }

    std::cout << odd_count << " " << last_odd << std::endl;

    return 0;
}