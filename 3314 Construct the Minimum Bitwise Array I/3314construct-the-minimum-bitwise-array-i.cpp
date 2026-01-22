
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int x = INT_MAX;
            int change = 0;
            int y;
            if(nums[i]==2){
                ans[i] = -1;
            }
            else{
            for(int j=0; j<31; j++){
                if((((nums[i]) & (1<<j)) == 0) && change == 0){
                    change = 1;
                    x = x ^ (1<<(j-1));
                    y = x & nums[i];
                }
            }
            ans[i] = y;
            }
        }
        return ans;
    }
};