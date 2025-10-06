#include <iostream>
#include <vector>

int main() {
    int n;
    int k;
    int t;
    std::cin >> n >> k >> t;

    std::vector<int> depths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> depths[i];
    }

    int valid_sections_count = 0;
    int deep_enough_count = 0;

    for (int i = 0; i < k; ++i) {
        if (depths[i] >= t) {
            deep_enough_count++;
        }
    }

    if (deep_enough_count * 2 >= k) {
        valid_sections_count++;
    }

    for (int i = 1; i <= n - k; ++i) {
        if (depths[i - 1] >= t) {
            deep_enough_count--;
        }

        if (depths[i + k - 1] >= t) {
            deep_enough_count++;
        }

        if (deep_enough_count * 2 >= k) {
            valid_sections_count++;
        }
    }

    std::cout << valid_sections_count << std::endl;

    return 0;
}