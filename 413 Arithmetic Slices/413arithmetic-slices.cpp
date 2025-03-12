class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int c=0, r=1, sum=0;
        while(r<n-1){
            if (2*nums[r] == ((long long)nums[r+1] + (long long)nums[r-1])) {
                c++;
            }
            else{
                sum += (c*(c+1))/2;
                c = 0;
            }
            r++;
        }
        if(c!=0) sum += (c*(c+1))/2;
        return sum;
    }
};