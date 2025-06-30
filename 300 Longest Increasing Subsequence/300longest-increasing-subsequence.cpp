class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n,1);
        int lis = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    vec[i] = max(vec[i],vec[j]+1);
                    lis = max(lis,vec[i]);
                }
            }
        }
        return lis;
    }
};