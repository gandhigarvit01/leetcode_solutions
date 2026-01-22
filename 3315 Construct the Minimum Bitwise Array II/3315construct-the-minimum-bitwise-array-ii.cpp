class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i = 0;i<n;i++) {
            int num = nums[i];
            if(num%2==0) continue;
            for(int j = 0;j<32;j++) {
                if((num & (1<<j))==0) {
                    if(j>0) num = num ^ (1<<(j-1));
                    ans[i] = num;
                    break;
                }
            }
        }
        return ans;
    }
};