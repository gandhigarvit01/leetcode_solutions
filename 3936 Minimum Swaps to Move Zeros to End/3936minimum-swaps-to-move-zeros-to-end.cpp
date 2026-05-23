class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zeros++;
        }
        int i = n-1;
        int ans = 0;
        while(zeros>0){
            if(nums[i]!=0) ans++;
            zeros--;
            i--;
        }
        return ans;
    }
};