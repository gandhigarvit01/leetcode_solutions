class Solution {
public:
    int n;
    int dp[101][101];
    int solve(int i, vector<int>& piles, int M) {
        if (i >= n)
            return 0;
        if (dp[i][M] != INT_MIN)
            return dp[i][M];
        int X = 2 * M;
        int ans = INT_MIN;
        int res;
        int sum = 0;
        for (int idx = 0; idx < X; idx++) {
            if (i + idx < n) {
                sum += piles[i + idx];
                res = sum - solve(i + idx + 1, piles, max(M, idx + 1));
                ans = max(ans, res);
            }
        }
        return dp[i][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        for (int i = 0; i < 101; i++){
            for (int j = 0; j < 101; j++){
                dp[i][j] = INT_MIN;
            }
        }
        int total = 0;
        for (int x : piles)
            total += x;
        int ans = solve(0, piles, 1);
        int alice_score = (ans + total) / 2;
        return alice_score;
    }
};