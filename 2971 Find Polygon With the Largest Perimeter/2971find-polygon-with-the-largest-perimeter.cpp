class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long perimeter = 0;
        long long sum = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        sum = nums[0]+nums[1];
        for(int i=2; i<n; i++){
            if(sum>nums[i]){
                sum += nums[i];
                perimeter = sum;
            }
            else{
                sum += nums[i];
            }
        }
        return perimeter>0?perimeter:-1;
    }
};