class Solution {
public:
    bool issort(vector<int>& nums){
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }

    vector<int> operate(vector<int>& nums){
        int n = nums.size();
        int sum = INT_MAX;
        vector<int> ans(n-1);
        int k=0;
        for(int i=0; i<n-1; i++){
            if(sum > nums[i]+nums[i+1]){
                sum = nums[i]+nums[i+1];
                k = i;
            }
        }
        for(int j=0; j<k; j++){
            ans[j] = nums[j];
        }
        ans[k] = sum;
        for(int j=k+1; j<n-1; j++){
            ans[j] = nums[j+1];
        }
        return ans;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(!issort(nums)){
            operations++;
            vector<int> ans = operate(nums);
            int m = ans.size();
            nums.resize(m);
            nums = ans;
        }
        return operations;
    }
};