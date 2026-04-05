class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<long long> cost(n, 0);
        for(int i=1; i<n-1; i++){
            int maxi = max(nums[i-1],nums[i+1]) + 1;
            if(nums[i]<maxi) {
                cost[i]=maxi-nums[i];
            }
        }
        if(n%2==1){
            long long ans = 0;
            for(int i=1; i<n-1; i+=2){
                ans += cost[i];
            }
            return ans;
        }
        vector<long long> pref(n,0);
        vector<long long> suff(n,0);
        for(int i=1; i<n; i+=2){
            pref[i] = cost[i];
            if(i-2>=0) pref[i] += pref[i - 2];
        }
        for(int i=n-2; i>=2; i-=2){
            suff[i] = cost[i];
            if(i+2<n) suff[i] += suff[i + 2];
        }
        long long ans = LLONG_MAX;
        for(int i=1; i<n; i+=2) {
            long long left = pref[i];
            long long right = (i+3<n?suff[i+3]:0);
            ans = min(ans,left+right);
        }
        for(int i=n-2; i>=2; i-=2){
            long long right = suff[i];
            long long left = (i-3>0?pref[i-3]:0);
            ans = min(ans,left+right);
        }
        return ans;
    }
};