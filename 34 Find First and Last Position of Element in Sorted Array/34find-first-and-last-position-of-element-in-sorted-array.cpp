class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int m= nums.size();
        int l=0;
        int r=m-1;
        int a=-1;
        int b=-1;
        int mid= l+(r-l)/2;


        while(l<=r){
            if(nums[mid]==target){
                a= mid;
                r= mid-1;
            }
            else if(target>nums[mid]){
                l= mid+1;
            }
            else if(target<nums[mid]){
                r= mid-1;
            }

            mid= l+(r-l)/2;
            

        }
        l=0;
        r= m-1;
        mid= l+(r-l)/2;


        while(l<=r){
            if(nums[mid]==target){
                b= mid;
                l= mid+1;
            }
            else if(target>nums[mid]){
                l= mid+1;
            }
            else if(target<nums[mid]){
                r= mid-1;
            }

            mid= l+(r-l)/2;
            

        }

        
        if(a>-1 && b>-1){
     return {a,b};}
     else{
        return {-1,-1};
     }


    }
};