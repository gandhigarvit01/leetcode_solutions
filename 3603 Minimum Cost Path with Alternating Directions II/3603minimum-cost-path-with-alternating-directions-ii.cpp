class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        using T = tuple<long long, int, int, int>; // {cost, row, col, time % 2}
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        priority_queue<T, vector<T>, greater<T>> pq;
        dist[0][0][1] = 1 * 1; // start at (0,0) at time=1 (odd second)
        pq.push({1LL * 1 * 1, 0, 0, 1}); // initial cost, position, time parity

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}}; // right, down

        while (!pq.empty()) {
            auto [cost, i, j, parity] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1) return cost;

            if (dist[i][j][parity] < cost) continue;

            int next_parity = 1 - parity;

            if (parity == 1) { // move on odd seconds
                for (auto [dx, dy] : dir) {
                    int ni = i + dx, nj = j + dy;
                    if (ni < m && nj < n) {
                        long long new_cost = cost + 1LL * (ni + 1) * (nj + 1);
                        if (new_cost < dist[ni][nj][next_parity]) {
                            dist[ni][nj][next_parity] = new_cost;
                            pq.push({new_cost, ni, nj, next_parity});
                        }
                    }
                }
            } else { // wait on even seconds
                long long new_cost = cost + waitCost[i][j];
                if (new_cost < dist[i][j][next_parity]) {
                    dist[i][j][next_parity] = new_cost;
                    pq.push({new_cost, i, j, next_parity});
                }
            }
        }

        return -1;
    }
};
