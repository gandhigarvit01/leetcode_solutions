class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> ans(n);
        ans[0] = costs[0] + 1;
        if(1<n){
            ans[1] = ans[0] + costs[1] + 1;
            ans[1] = min(ans[1], costs[1] + 4);
        }
        if(2<n){
            ans[2] = ans[1] + costs[2] + 1;
            ans[2] = min(ans[2], ans[0] + costs[2] + 4);
            ans[2] = min(ans[2], costs[2] + 9);
        }
        for(int i=3; i<n; i++){
            ans[i] = ans[i-1] + costs[i] + 1;
            ans[i] = min(ans[i], ans[i-2] + costs[i] + 4);
            ans[i] = min(ans[i], ans[i-3] + costs[i] + 9);
            
        }
        return ans[n-1];
    }
};