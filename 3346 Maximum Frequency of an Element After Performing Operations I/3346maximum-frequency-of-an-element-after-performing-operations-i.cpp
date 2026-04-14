class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int offset = 0;
        if(nums[0]-k<0) offset = abs(nums[0] - k);
        int maxi = nums[n-1] + k + offset + 1;
        vector<int> pre(maxi,0);
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
            int l = nums[i]-k;
            int r = nums[i]+k;
            pre[l+offset]++;
            if(r+offset+1 < maxi) pre[r+offset+1]--;
        }
        for(int i=0; i<maxi; i++){
            if(i>0) pre[i] += pre[i-1];
        }
        for(int i=0; i<maxi; i++){
            int val = pre[i];
            if(mpp.count(i-offset)) val -= mpp[i-offset];
            if(val > numOperations) val = numOperations;
            if(mpp.count(i-offset)) val += mpp[i-offset];
            ans = max(ans, val);
        }
        return ans;
    }
};