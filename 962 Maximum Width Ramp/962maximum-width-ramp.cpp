class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightmax(n);
        rightmax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i+1],nums[i]);
        }
        int ramp = 0;
        int i=0, j=0;
        while(j<n){
            if(rightmax[j]>=nums[i]){
                ramp = max(ramp, j-i);
                j++;
            }
            else{
                if(i<j) i++;
                else{
                    i++;
                    j++;
                }
            }  
        }
        return ramp;
    }
};