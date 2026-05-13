class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sum(2*limit+1,0);
        unordered_map<int,int> mpp;
        for(int i=0; i<n/2; i++){
            mpp[nums[i]+nums[n-1-i]]++;
            int c = min(1+nums[n-1-i], 1+nums[i]);
            int d = max(limit+nums[n-1-i], limit+nums[i]);
            sum[c]+=1;
            if(d+1 <= 2*limit) sum[d+1]-=1;
            int a = 1;
            int b = c-1;
            sum[a] += 2;
            sum[b+1] -= 2;
            int e = d+1;
            if(e<=2*limit) sum[e] += 2;
        }
        for(int i=2; i<2*limit+1; i++){
            sum[i] += sum[i-1];
        }
        int ans = INT_MAX;
        for(int i=2; i<2*limit+1; i++){
            int k = sum[i];
            if(mpp.find(i)!=mpp.end()) k-=mpp[i];
            ans = min(ans, k);
        }
        return ans;
    }
};