class Solution {
public:
    int mini = INT_MAX, maxi = INT_MIN;
    int prev, op, n;
    void solve(vector<int>& nums){
        for(int i=1; i<n; i++){
            if((prev==0 && nums[i]%2!=0) || (prev==1 && nums[i]%2==0)){
                // do nothing
            }
            else{
                op++;
                if(nums[i]==maxi && nums[i]==mini) nums[i] -= 1;
                else if(nums[i]==maxi) nums[i] -= 1;
                else if(nums[i]==mini) nums[i] += 1;
            }
            prev = 1-prev;
        }
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        n = nums.size();
        int min_op, min_diff;
        vector<int> nums1 = nums;
        for(int i=0; i<n; i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        op = 0;
        if(nums[0]%2==0) prev = 0;
        else prev = 1;
        solve(nums1);   // 1st call
        min_op = op;
        mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mini = min(mini,nums1[i]);
            maxi = max(maxi,nums1[i]);
        }
        min_diff = maxi-mini;
        nums1 = nums;
        mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mini = min(mini,nums1[i]);
            maxi = max(maxi,nums1[i]);
        }
        op = 1;
        if(nums[0]%2==0) prev = 1;
        else prev = 0;
        if(nums1[0]==maxi && nums1[0]==mini) nums1[0] -= 1;
        else if(nums1[0]==maxi) nums1[0] -= 1;
        else if(nums1[0]==mini) nums1[0] += 1;
        solve(nums1);   // 2nd call
        mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mini = min(mini,nums1[i]);
            maxi = max(maxi,nums1[i]);
        }
        if(op<min_op){
            min_op = op;
            min_diff = maxi-mini;
        }
        else if(op==min_op){
            min_op = op;
            min_diff = min(min_diff, maxi-mini);
        }
        return {min_op,min_diff};
    }
};