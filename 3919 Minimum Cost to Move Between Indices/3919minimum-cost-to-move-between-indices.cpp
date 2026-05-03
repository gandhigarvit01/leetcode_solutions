class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> forward(n,0);
        vector<int> backward(n,0);
        if(n>1){
            forward[1] = 1;
            backward[n-2] = 1;
        }
        for(int i=1; i<n-1; i++){
            if(abs(nums[i+1]-nums[i]) < abs(nums[i-1]-nums[i])){
                forward[i+1] = 1;
            }
            else forward[i+1] = abs(nums[i+1]-nums[i]);
        }
        for(int i=n-2; i>0; i--){
            if(abs(nums[i-1]-nums[i]) <= abs(nums[i+1]-nums[i])){
                backward[i-1] = 1;
            }
            else backward[i-1] = abs(nums[i-1]-nums[i]);
        }
        for(int i=1; i<n; i++){
            forward[i] += forward[i-1];
        }
        for(int i=n-2; i>=0; i--){
            backward[i] += backward[i+1];
        }
        int m = queries.size();
        vector<int> ans(m,0);
        for(int i=0; i<m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==r) ans[i] = 0;
            else if(l<r){
                ans[i] = forward[r] - forward[l];
            }
            else{
                ans[i] = backward[r] - backward[l];
            }
        }
        return ans;
    }
};