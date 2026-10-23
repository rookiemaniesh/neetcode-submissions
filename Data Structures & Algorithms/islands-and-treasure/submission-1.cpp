class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF = 2147483647;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) q.push({i, j});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                if (grid[ni][nj] != INF) continue;   // wall, treasure, or already visited
                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
};