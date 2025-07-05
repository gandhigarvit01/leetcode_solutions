class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2], e[3]});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0] = 0;

        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();
            if (t > dist[u]) continue;

            for (auto& [v, start, end] : graph[u]) {
                if (t > end) continue;
                int waitTime = max(start, t);
                if (waitTime + 1 < dist[v]) {
                    dist[v] = waitTime + 1;
                    q.push({v, waitTime + 1});
                }
            }

            if (t + 1 < dist[u]) {
                dist[u] = t + 1;
                q.push({u, t + 1});
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
