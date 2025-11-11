class Solution {
public:
    int l;
    int dp[101][101][601];
    int solve(vector<string>& strs, int m, int n, int i){
        int zeros = 0, ones = 0;
        if(i==l){
            return dp[m][n][i] = 0;
        }
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        int take = 0, skip = 0;
        for(int j=0; j<strs[i].size(); j++){
            if(strs[i][j]=='0'){
                zeros++;
            }
            else{
                ones++;
            }
        }
        if(m>=zeros && n>=ones){
            take = 1 + solve(strs,m-zeros,n-ones,i+1);
        }
        skip = solve(strs,m,n,i+1);
        return dp[m][n][i] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        l = strs.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(strs,m,n,0);
        return ans;
    }
};