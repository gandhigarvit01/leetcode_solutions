class Solution {
public:
    int m,n;
    long long dp[101][4][102][102];
    long long solve(int i, int rem, int num1, int num2, vector<vector<pair<int,int>>>& vec){
        if(rem==0) return 0;
        if(i==m) return LLONG_MIN;
        if(dp[i][rem][num1][num2]!=LLONG_MIN) return dp[i][rem][num1][num2];
        long long skip = LLONG_MIN, take = LLONG_MIN;
        long long ans = LLONG_MIN;
        // skip
        skip = solve(i+1, rem, num1, num2, vec);
        // take
        for(int k=n-1; k>=n-3; k--){
            int col = vec[i][k].second;
            int val = vec[i][k].first;

            if(col!=num1 && col!=num2){
                int nnum1 = num1, nnum2 = num2;
                if(nnum1==101) nnum1 = col;
                else if(nnum2==101) nnum2 = col;
                if(nnum1 > nnum2) swap(nnum1, nnum2);

                ans = solve(i+1, rem-1, nnum1, nnum2, vec);
                if(ans!=LLONG_MIN) ans += val;
                take = max(ans, take);
            }
        }
        return dp[i][rem][num1][num2] = max(skip, take);
    }
    long long maximumValueSum(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        fill(&dp[0][0][0][0], &dp[0][0][0][0] + 101*4*102*102, LLONG_MIN);
        vector<vector<pair<int,int>>> vec(m, vector<pair<int,int>>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vec[i][j].first = board[i][j];
                vec[i][j].second = j;
            }
        }
        for(int i=0; i<m; i++){
            sort(vec[i].begin(),vec[i].end());
        }
        return solve(0, 3, 101, 101, vec);
    }
};