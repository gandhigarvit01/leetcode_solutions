class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int rank = 0;
        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                rank++;
                ans += rank;
            }
            else{
                ans += rank;
            }
        }
        return ans;
    }
};