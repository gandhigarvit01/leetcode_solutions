class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        if(n==3){
            return max(nums[0],max(nums[1],nums[2]));
        }
        int l=-1,k=-1;
        int a = nums[0];
        int b = max(a,nums[1]);
        int c=-1;
        for(int i=2; i<n-1; i++){
            c = max(b,a+nums[i]);
            a = b;
            b = c;
        }
        l = c;
        a = nums[1];
        b = max(a,nums[2]);
        for(int i=3; i<n; i++){
            c = max(b,a+nums[i]);
            a = b;
            b = c;
        }
        k = c;
        return max(l,k);
    }
};