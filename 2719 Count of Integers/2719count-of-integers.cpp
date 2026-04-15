class Solution {
public:
    int mod = 1e9+7;
    int mini, maxi;
    int dp[24][2][401];
    int solve(string& s, int idx, bool tight, int sum){
        if(idx==s.size()){
            if(sum>=mini) return 1;
            return 0;
        }
        if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
        int lb = 0;
        int ub = (tight==true) ? s[idx]-'0' : 9;
        int ans = 0;
        for(int dig = lb; dig <= ub; dig++){
            if(sum + dig > maxi) continue;
            ans = (ans + solve(s, idx+1, (tight && dig==ub) ,sum + dig)) % mod;
        }
        return dp[idx][tight][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        mini = min_sum;
        maxi = max_sum;
        memset(dp, -1, sizeof(dp));
        int l = solve(num1, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        int r = solve(num2, 0, 1, 0);
        int res = (r-l+mod)%mod;
        // add 1 if num1 is good
        int num1_sum = 0;
        for(int i=0; i<num1.size(); i++){
            num1_sum += (num1[i]-'0');
        }
        if(num1_sum >= mini && num1_sum <= maxi) res = (res + 1)%mod;
        return res;
    }
};