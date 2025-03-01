class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        int k=-1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                k=i;
                break;
            }
        }
        if(k==-1 || k==n-1) return nums;
        int start=k;
        int end=k+1;
        while(end<n){
            if(nums[end]==0){
                end++;
            }
            else{
                swap(nums[start],nums[end]);
                start++;
                end++;
            }
        }

        return nums;
    }
};