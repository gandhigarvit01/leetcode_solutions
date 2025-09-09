class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> day(n,0);
        int l=0,r=0;
        int mod = 1e9+7;
        day[0] = 1;
        long long prev = 0;
        for(int i=delay; i<forget; i++){
            prev = (prev+day[r])%mod;
            day[i] = (prev+day[i])%mod;
            r++;
        }
        for(int i=forget; i<n; i++){
            prev = (prev+day[r])%mod;
            prev = (prev-day[l]+mod)%mod;
            l++;
            day[i] = (day[i]+prev)%mod; 
            r++;
        }
        long long ans = 0;
        for(int i=n-1; i>=n-forget; i--){
            ans = (ans+day[i])%mod;
        }
        return (int)ans;
    }
};