#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    map<int, int> counts;
    for (int i = 0; i < N; ++i) {
        int s;
        cin >> s;
        counts[s]++;
    }

    int removals = 0;
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        int val = it->first;
        int count = it->second;

        if (count < val) {
            // If we have fewer occurrences than the value itself,
            // we must remove all of them (we can't reach 'val' occurrences).
            removals += count;
        } else {
            // If we have enough occurrences, we keep exactly 'val' of them
            // and remove the excess.
            removals += (count - val);
        }
    }

    cout << removals << endl;

    return 0;
}
