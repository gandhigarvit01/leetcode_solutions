class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            if((i-k>-1) && (i+k<n)){
                if(nums[i]>nums[i-k] && nums[i]>nums[i+k]){
                    sum += nums[i];
                }
            }
            else if((i-k>-1) && (nums[i]>nums[i-k])){
                sum += nums[i];
            }
            else if((i+k<n) && (nums[i]>nums[i+k])){
                sum += nums[i];
            }
            else if((i-k<0) && (i+k>n-1)){
                sum += nums[i];
            }
        }
        return sum;
    }
};