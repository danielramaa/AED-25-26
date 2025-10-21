#include <algorithm>
#include <iostream>
#include <vector>

struct Number {
    int n_{};
    int bits_{};
};


int countBits(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n & 1);
        n >>= 1;
    }
    return ans;
}

bool compare(int n, int n1) {

    return n < n1;
}

int main() {

    int n;
    std::cin >> n;
    std::vector<Number> nums;
    nums.reserve(n);

    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        Number item{value, countBits(value)};
        nums.push_back(item);
    }

    std::sort(nums.begin(), nums.end(),compare(nums[i].n_, nums[i+1].n_));


    for (int i = 0; i < (int)nums.size(); i++) {
        std::cout << nums[i].n_ << std::endl;
    }
    return 0;
}