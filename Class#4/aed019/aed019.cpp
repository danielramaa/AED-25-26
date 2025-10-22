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

bool compare(const Number& a, const Number& b) {
    if (a.bits_ != b.bits_) return a.bits_ > b.bits_;
    return a.n_ < b.n_;
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

    std::sort(nums.begin(), nums.end(), compare);

    for (int i = 0; i < (int)nums.size(); i++) {
        std::cout << nums[i].n_ << std::endl;
    }
    return 0;
}