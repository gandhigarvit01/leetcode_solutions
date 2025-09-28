class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a,b;
        int c=-1;

        int par=0;
        for(int i=2;i<nums.size();i++){
           
            a=nums[i-2];
            b=nums[i-1];
            c=nums[i];
            
            if(a+b>c&&a+c>b&&b+c>a) par=a+b+c;
            
        }

        return par;
    }
};