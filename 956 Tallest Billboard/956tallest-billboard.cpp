class Solution {
public:
    int n;
    int dp[21][10003];
    int solve(int idx, int diff, vector<int>& rods){
        if(idx==n){
            if(diff==0){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        if(dp[idx][diff+5000]!=-1){
            return dp[idx][diff+5000];
        }
        int reject = solve(idx+1,diff,rods);
        int case1 = rods[idx] + solve(idx+1,diff+rods[idx],rods);
        int case2 = rods[idx] + solve(idx+1,diff-rods[idx],rods);
        return dp[idx][diff+5000] = max(reject,max(case1,case2));
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,rods)/2;   
    }
};