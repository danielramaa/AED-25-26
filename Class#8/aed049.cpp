#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    map<int, int> last_seen;
    
    for (int i = 0; i < N; ++i) {
        int event;
        cin >> event;
        
        if (last_seen.find(event) != last_seen.end()) {
            cout << last_seen[event] + 1; 
        } else {
            cout << -1;
        }
        
        last_seen[event] = i;

        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
