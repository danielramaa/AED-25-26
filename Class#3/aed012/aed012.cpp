#include <iostream>
#include <vector>

int lowerBound(const std::vector<int> & v, int key) {
    int l = 0;
    int r = v.size();
    int ans = -1;


    while (l < r) {
        int m = l + (r-l) / 2;
        if (v[m] >= key) {
            ans = m;
            r = m;
        } else {
            l = m + 1;
       }
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i=0; i<n; i++) {
        std::cin >> v[i];
    }
    int query_quantity;
    std::cin >> query_quantity;

    for (int i=0; i< query_quantity; i++) {
        int query;
        std::cin >> query;
        int index = lowerBound(v, query);
        std::cout << index << "\n";
    }
    return 0;
}