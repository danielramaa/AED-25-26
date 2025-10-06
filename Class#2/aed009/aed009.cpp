#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    int max_so_far = sequence[0];
    int max_ending_here = sequence[0];

    for (int i = 1; i < n; ++i) {
        int current_number = sequence[i];
        max_ending_here = std::max(current_number, max_ending_here + current_number);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    std::cout << max_so_far << std::endl;

    return 0;
}