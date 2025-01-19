class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=-1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                k=i;
                break;
            }
           
        }
        int start=k;
        int end=k+1;
        while(end<n){
            if(k==-1){
                break;
            }

            if(nums[end]==0){
                end++;
            }
            else{
                swap(nums[start],nums[end]);
                start++;
                end++;
            }
        }
    }
};