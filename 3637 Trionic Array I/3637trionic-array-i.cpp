class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n==3) return false;
        int p=0,q=0,pin=n,qin=n;
        for(int i=1; i<n-1; i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i-1]){
                return false;
            }
            if(p>1 || q>1 || qin<pin){
                return false;
            }
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                p++;
                pin = i;
            }
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                q++;
                qin = i;
            }
        }
        if(p==1 && q==1 && pin<qin){
            return true;
        }
        return false;
    }
};