#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Process {
    string name;
    int timeLeft;
};

int main() {
    int T, N;
    cin >> T >> N;
    
    queue<Process> processes;
    
    for (int i = 0; i < N; i++) {
        string name;
        int time;
        cin >> name >> time;
        processes.push({name, time});
    }
    
    int currentTime = 0;
    int iterations = 0;
    
    while (!processes.empty()) {
        Process current = processes.front();
        processes.pop();
        iterations++;
        
        if (current.timeLeft <= T) {
            currentTime += current.timeLeft;
            cout << current.name << " " << currentTime << " " << iterations << endl;
        } else {
            currentTime += T;
            current.timeLeft -= T;
            processes.push(current);
        }
    }
    
    return 0;
}