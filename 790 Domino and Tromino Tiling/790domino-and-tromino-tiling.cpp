class Solution {
public:
    int dp[1003][2050];
    int mod = 1e9+7;
    int solve(int i, int n, vector<vector<int>>& vec, int total){
        if(i>=n){
            if(total==2*n){
                return 1;
            }
            return 0;
        }
        if(dp[i][total]!=-1){
            return dp[i][total];
        }
        if(vec[1][i]==0){
            if(i>=1 && vec[1][i-1]==0){
                vec[1][i-1] = 1;
                vec[1][i] = 1;
                total += 2;
                int a = solve(i,n,vec,total)%mod;
                vec[1][i-1] = 0;
                vec[1][i] = 0;
                total -= 2;

                vec[1][i-1] = 1;
                vec[1][i] = 1;
                vec[0][i] = 1;
                total += 3;
                int b = solve(i+1,n,vec,total)%mod;
                vec[1][i-1] = 0;
                vec[1][i] = 0;
                vec[0][i] = 0;
                total -= 3;

                return dp[i][total] = (a+b)%mod;
            }
            else{
                vec[0][i] = 1;
                vec[1][i] = 1;
                total += 2;
                int a = solve(i+1,n,vec,total)%mod;
                vec[0][i] = 0;
                vec[1][i] = 0;
                total -= 2;

                vec[0][i] = 1;
                vec[1][i] = 1;
                vec[1][i+1] = 1;
                total += 3;
                int b = solve(i+1,n,vec,total)%mod;
                vec[0][i] = 0;
                vec[1][i] = 0;
                vec[1][i+1] = 0;
                total -= 3;

                vec[0][i] = 1;
                vec[1][i] = 1;
                vec[0][i+1] = 1;
                total += 3;
                int c = solve(i+2,n,vec,total)%mod;
                vec[0][i] = 0;
                vec[1][i] = 0;
                vec[0][i+1] = 0;
                total -= 3;

                vec[0][i] = 1;
                vec[1][i] = 1;
                vec[0][i+1] = 1;
                vec[1][i+1] = 1;
                total += 4;
                int d = solve(i+2,n,vec,total)%mod;
                vec[0][i] = 0;
                vec[1][i] = 0;
                vec[0][i+1] = 0;
                vec[1][i+1] = 0;
                total -= 4;

                return dp[i][total] = (((a+b)%mod+c)%mod+d)%mod;
            }
        }
        else{
            vec[0][i] = 1;
            vec[0][i+1] = 1;
            total += 2;
            int a = solve(i+2,n,vec,total)%mod;
            vec[0][i] = 0;
            vec[0][i+1] = 0;
            total -= 2;

            vec[0][i] = 1;
            vec[0][i+1] = 1;
            vec[1][i+1] = 1;
            total += 3;
            int b = solve(i+2,n,vec,total)%mod;
            vec[0][i] = 0;
            vec[0][i+1] = 0;
            vec[1][i+1] = 0;
            total -= 3;

            return dp[i][total] = (a+b)%mod;
        }
        return 0;
    }
    int numTilings(int n) {
        vector<vector<int>> vec(2, vector<int>(n+1, 0));
        memset(dp, -1, sizeof(dp));
        return solve(0,n,vec,0)%mod;;
    }
};