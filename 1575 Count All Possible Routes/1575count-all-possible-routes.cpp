class Solution {
public:
    int n;
    int dp[101][201];
    int mod = 1e9+7;
    int solve(int idx,vector<int>& locations, int fuel, int finish){
        if(fuel<0){
            return 0;
        }
        if(dp[idx][fuel]!=-1){
            return dp[idx][fuel];
        }
        int ans = 0;
        if(idx==finish){
            ans++;
        }
        for(int i=0; i<n; i++){
            if(i!=idx){
                ans = (ans + (solve(i, locations, fuel-abs(locations[i]-locations[idx]), finish))%mod)%mod;
            }
        }
        return dp[idx][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(start,locations,fuel,finish);
    }
};