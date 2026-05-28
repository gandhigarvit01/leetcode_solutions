class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int pro = 1;
        int lastneg = 1;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                maxi = max(maxi, 0);
                pro = 1;
                lastneg = 1;
            }
            else{
                pro = pro*nums[i];
                if(pro<0){
                    maxi = max(maxi, pro);
                    maxi = max(maxi, pro/lastneg);
                    if(lastneg==1) lastneg = pro;
                }
                else{
                    maxi = max(maxi, pro);
                }
            }
        }
        return maxi;
    }
};