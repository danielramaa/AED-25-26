#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    //number of players
    int n;
    //number of top scores i want
    int k;
    std::cin >> n >> k;

    std::vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        std::cin >> scores[i];
    }

    std::sort(scores.begin(), scores.end());

    for (int i = n - 1; i >= n - k; i--) {
        std::cout << scores[i] << std::endl;
    }


    return 0;
}