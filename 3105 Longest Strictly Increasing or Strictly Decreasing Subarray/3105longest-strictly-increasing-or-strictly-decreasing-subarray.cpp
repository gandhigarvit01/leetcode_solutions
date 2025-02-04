class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int m=1,k=1,c=1;
        for(int i=1; i<n; i++ ){
            if(nums[i]>nums[i-1]){
                c=1;
                m++;
                k= max(k,m);
            }
            else if(nums[i]<nums[i-1]){
                m=1;
                c++;
                k=max(k,c);
            }
            else{
                m=1;
                c=1;
            }
        }
        return k;

    }
};