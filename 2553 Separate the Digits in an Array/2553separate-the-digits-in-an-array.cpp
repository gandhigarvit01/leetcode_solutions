class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            int val = nums[i];
            while(val>0){
                int rem = val%10;
                val = val/10;
                ans.push_back(rem);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};