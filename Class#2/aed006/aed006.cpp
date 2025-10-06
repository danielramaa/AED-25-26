// [AED006] Bakugans
// A naive O(N*P) solution

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Read Bakugans energy
    int n;
    cin >> n;
    vector<long long> prefix_sum(n + 1, 0);

    for (int i=1; i<=n; ++i) {
        int energy;
        cin >> energy;
        prefix_sum[i] = prefix_sum[i - 1] + energy;
    }


    // Read and process photos
    int p;
    cin >> p;
    for (int i=0; i<p; i++) {
        int a, b;
        std::cin >> a >> b;

        long long result = prefix_sum[b] - prefix_sum[a - 1];
        std::cout << result << "\n";
    }

    return 0;
}