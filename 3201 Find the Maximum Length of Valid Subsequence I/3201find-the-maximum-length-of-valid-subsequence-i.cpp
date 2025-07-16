class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int allodds = 0;
        int allevens = 0;
        int oddeven = 0;
        int evenodd = 0;
        int prev1 = -1, prev2 = -1;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                allevens++;
                if(prev1!=-1 && nums[prev1]%2!=0){
                    oddeven++;
                    prev1 = i;
                }
                if(prev2==-1 || nums[prev2]%2!=0){
                    evenodd++;
                    prev2 = i;
                }
            }
            else{
                allodds++;
                if(prev1==-1 || nums[prev1]%2==0){
                    oddeven++;
                    prev1 = i;
                }
                if(prev2!=-1 && nums[prev2]%2==0){
                    evenodd++;
                    prev2 = i;
                }
            }
        }
        return max(max(allodds,allevens),max(oddeven,evenodd));
    }
};