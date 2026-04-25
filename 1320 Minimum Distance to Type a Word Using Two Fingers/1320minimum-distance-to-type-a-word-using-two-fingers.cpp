class Solution {
public:
    int n;
    int dp[300][6][6][6][6];
    int solve(string& word, int i, int x1, int y1, int x2, int y2){
        if(i==n) return 0;
        if(dp[i][x1][y1][x2][y2]!=-1) return dp[i][x1][y1][x2][y2];
        int ans = 0;
        int val = word[i]-'A';
        int row = val/6;
        int col = val%6;
        if(x1==4 && y1==4){
            ans = solve(word, i+1, row, col, x2, y2);
        }
        else{
            ans = abs(x1-row) + abs(y1-col) + solve(word, i+1, row, col, x2, y2);
        }
        int ans2 = 0;
        if(x2==4 && y2==4){
            ans2 = solve(word, i+1, x1, y1, row, col);
        } 
        else{
            ans2 = abs(row-x2) + abs(col-y2) + solve(word, i+1, x1, y1, row, col); 
        }
        return dp[i][x1][y1][x2][y2] = min(ans, ans2);
    }
    int minimumDistance(string word) {
        n = word.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(word, 0, 4, 4, 4, 4);
        return ans;
    }
};