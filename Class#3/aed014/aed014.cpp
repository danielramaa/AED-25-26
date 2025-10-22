#include <bits/stdc++.h>
using namespace std;

static bool isPossible(const vector<int>& v, long long x, int k) {
    
    long long cur = 0;
    int parts = 1;
    for (int d : v) {
        if (d > x) return false;
        if (cur + d <= x) {
            cur += d;
        } else {
            parts++;
            cur = d;
            if (parts > k) return false;
        }
    }
    return parts <= k;
}

static long long minimalMaxPartitionSum(const vector<int>& v, int k) {
    long long lo = 0, hi = 0;
    for (int d : v) {
        lo = max(lo, (long long)d);
        hi += d;
    }
    
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (isPossible(v, mid, k)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> d(N);
    for (int i = 0; i < N; ++i) cin >> d[i];
    int Q; cin >> Q;
    for (int qi = 0; qi < Q; ++qi) {
        int K; cin >> K;
        cout << minimalMaxPartitionSum(d, K) << '\n';
    }
    return 0;
}