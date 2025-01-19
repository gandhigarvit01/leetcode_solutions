class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=1;
        while(end<n){
            if(nums[end]==nums[start]){
                end++;

            }
            else{
                nums[start+1]=nums[end];
                start++;
                end++;
            
            }
        }
        return start+1;
    }
};