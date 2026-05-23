class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            sort(nums.begin(), nums.end());
        }
        else{
            for(int i=n-1; i>idx; i--){
                if(nums[i] > nums[idx]){
                    int temp = nums[idx];
                    nums[idx] = nums[i];
                    nums[i] = temp;
                    break;
                }
            }
            sort(nums.begin()+idx+1, nums.end());
        }
    }
};