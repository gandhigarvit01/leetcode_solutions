class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1]){
            return -1;
        }
        int count = 1;
        int operations = 0;
        for(int i=1; i<=n; i++){
            if(i!=n && nums[i]==nums[i-1]){
                count++;
            }
            else{
                if(count==1){
                    return -1;
                }
                if(count==2){
                    operations++;
                    count = 1;
                }
                else if(count%3==0){
                    operations += count/3;
                    count = 1;
                }
                else{
                    operations += count/3 + 1;
                    count = 1;
                }
            }
        }
        return operations;
    }
};