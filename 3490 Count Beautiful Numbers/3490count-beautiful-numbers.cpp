class Solution {
public:
    int dp[11][2][91][91];
    int solve(string& s, int idx, bool tight, int sum, int pro, int tar){
        if(idx==s.size()){
            if(sum==tar){
                return (pro % sum == 0); 
            }
            return 0;
        }
        if(dp[idx][tight][sum][pro]!=-1) return dp[idx][tight][sum][pro];
        int ub = (tight==true)? s[idx]-'0' : 9;
        int ans = 0;
        for(int i=0; i<=ub; i++){
            bool new_tight = (tight && i==ub);
            int new_sum = sum + i;
            if(new_sum > tar) continue;
            int new_pro = pro;
            if(new_sum!=0) new_pro = (pro*i) % tar;
            ans += solve(s, idx+1, new_tight, new_sum, new_pro, tar);
        }
        return dp[idx][tight][sum][pro] = ans;
    }
    int beautifulNumbers(int l, int r) {
        string s1 = to_string(l-1);
        string s2 = to_string(r);
        int left = 0;
        for(int sum=1; sum<=90; sum++){
            memset(dp, -1, sizeof(dp));
            left += solve(s1,0,1,0,1,sum);
        }
        int right = 0;
        for(int sum=1; sum<=90; sum++){
            memset(dp, -1, sizeof(dp));
            right += solve(s2,0,1,0,1,sum);
        }
        return right - left;
    }
};