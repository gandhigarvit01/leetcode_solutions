class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,int> mpp;
        for(int i=n-1; i>=0; i--){
            int val = nums[i];
            int rev = 0;
            while(val>0){
                int rem = val%10;
                rev = rev*10 + rem;
                val = val/10;
            }
            if(mpp.count(rev)){
                int idx = mpp[rev];
                if(idx!=i) ans = min(ans, abs(idx-i));
            }
            mpp[nums[i]] = i;
        }
        return ans==INT_MAX? -1: ans;   
    }
};