class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;
    pair<long long, long long> memo[16][16];
    bool visited[16][16];
    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }
        if (visited[i][j]) return memo[i][j];
        long long mini, maxi;
        long long a, b, c, d;
        if (i + 1 < m && j + 1 < n) {
            pair<long long, long long> right = solve(i, j + 1, grid);
            pair<long long, long long> down = solve(i + 1, j, grid);
            
            a = right.first * grid[i][j], b = down.first * grid[i][j];
            c = right.second * grid[i][j], d = down.second * grid[i][j];
            
            mini = min({a, b, c, d});
            maxi = max({a, b, c, d});
        } 
        else if (i + 1 < m) {
            pair<long long, long long> down = solve(i + 1, j, grid);
            a = down.first * grid[i][j];
            b = down.second * grid[i][j];
            mini = min(a, b);
            maxi = max(a, b);
        } 
        else {
            pair<long long, long long> right = solve(i, j + 1, grid);
            a = right.first * grid[i][j];
            b = right.second * grid[i][j];
            mini = min(a, b);
            maxi = max(a, b);
        }
        visited[i][j] = true;
        return memo[i][j] = {mini, maxi};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) visited[i][j] = false;
        }
        pair<long long, long long> p = solve(0, 0, grid);
        if (p.second < 0) return -1;
        return p.second % mod;
    }
};