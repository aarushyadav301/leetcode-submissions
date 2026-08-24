class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> rowWalls(m, vector<int>(n));

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < guards.size(); i++) {
            rowWalls[guards[i][0]][guards[i][1]] = 1;
        }

        for (int i = 0; i < walls.size(); i++) {
            rowWalls[walls[i][0]][walls[i][1]] = 1;
        }
        
        int count = 0;

        for (int i = 0; i < guards.size(); i++) {
            int r = guards[i][0];
            int c = guards[i][1];

            for (int j = c + 1; j < n; j++) {
                if (!visited[r][j] && !rowWalls[r][j]) {
                    //cout << r << " " << j << endl;
                    visited[r][j] = true;
                    count++;
                    continue;
                }

                if (rowWalls[r][j]) {
                    break;
                }
            }

            for (int j = c - 1; j >= 0; j--) {
                if (!visited[r][j] && !rowWalls[r][j]) {
                    //cout << r << " " << j << endl;
                    visited[r][j] = true;
                    count++;
                    continue;
                }

                if (rowWalls[r][j]) {
                    break;
                }
            }

            for (int j = r + 1; j < m; j++) {
                if (!visited[j][c] && !rowWalls[j][c]) {
                    visited[j][c] = true;
                    count++;
                    continue;
                }

                if (rowWalls[j][c]) {
                    break;
                }
            }

            for (int j = r - 1; j >= 0; j--) {
                if (!visited[j][c] && !rowWalls[j][c]) {
                    visited[j][c] = true;
                    count++;
                    continue;
                }

                if (rowWalls[j][c]) {
                    break;
                }
            }
        }

        return (m * n - guards.size() - walls.size() - count);
    }
};