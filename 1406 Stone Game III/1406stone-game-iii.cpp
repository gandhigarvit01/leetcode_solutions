class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int total = 0;
        for (int x : stoneValue)
            total += x;

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // tabulation
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                int stones = 0;
                int ans = j == 0 ? INT_MIN : INT_MAX;
                if (j == 0) {
                    for (int idx = 0; idx <= 2; idx++) {
                        if (i + idx < n) {
                            stones += stoneValue[i + idx];
                            int res = stones + dp[i + idx + 1][1];
                            ans = max(ans, res);
                        }
                    }
                } else {
                    for (int idx = 0; idx <= 2; idx++) {
                        if (i + idx < n) {
                            int res = dp[i + idx + 1][0];
                            ans = min(ans, res);
                        }
                    }
                }
                dp[i][j] = ans;
            }
        }
        int alice = dp[0][0];
        int bob = total - alice;
        if (alice > bob)
            return "Alice";
        else if (bob > alice)
            return "Bob";
        return "Tie";
    }
};