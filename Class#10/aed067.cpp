#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int r, c, dist;
};

int main() {
    int n_cases;
    cin >> n_cases;
    
    while (n_cases--) {
        int rows, cols;
        cin >> rows >> cols;
        
        vector<string> maze(rows);
        int startR, startC;
        
        for (int i = 0; i < rows; i++) {
            cin >> maze[i];
            for (int j = 0; j < cols; j++) {
                if (maze[i][j] == 'P') {
                    startR = i;
                    startC = j;
                }
            }
        }
        
    
        queue<Node> q;
        q.push({startR, startC, 0});
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[startR][startC] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        int result = -1;
        
        while (!q.empty()) {
            Node current = q.front();
            q.pop();
            
            if (maze[current.r][current.c] == 'T') {
                result = current.dist;
                break;
            }
            
            for (int i = 0; i < 4; i++) {
                int nr = current.r + dr[i];
                int nc = current.c + dc[i];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                    maze[nr][nc] != '#' && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, current.dist + 1});
                }
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}

