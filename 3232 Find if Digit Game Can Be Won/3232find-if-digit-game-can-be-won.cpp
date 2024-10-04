class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum=0;
        int mus=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=10){
                sum=sum+nums[i];
            }
            else{
                mus=mus+nums[i];
            }
        }
        if(mus==sum) return false;
        else return true;
    }
};