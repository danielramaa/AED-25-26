#include <bits/stdc++.h>
using namespace std;

string sortString(const string &s) {
    string t;
    t.reserve(s.size());
    for (char c : s) {
        if (c != ' ') {
            t.push_back(static_cast<char>(tolower(static_cast<unsigned char>(c))));
        }
    }
    sort(t.begin(), t.end());
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    unordered_map<string, int> freq;
    freq.reserve(static_cast<size_t>(N) * 2);

    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        string key = sortString(line);
        ++freq[key];
    }

    int classes = 0;
    for (const auto &p : freq) {
        if (p.second >= 2) ++classes;
    }

    cout << classes << '\n';
    return 0;
}