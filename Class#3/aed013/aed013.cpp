#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];

    int Q;
    cin >> Q;
    while (Q--) {
        long long A, B;
        cin >> A >> B;
        // count of elements in [A, B] = first index > B minus first index >= A
        auto itL = lower_bound(v.begin(), v.end(), A);
        auto itR = upper_bound(v.begin(), v.end(), B);
        cout << (itR - itL) << "\n";
    }
    return 0;
}