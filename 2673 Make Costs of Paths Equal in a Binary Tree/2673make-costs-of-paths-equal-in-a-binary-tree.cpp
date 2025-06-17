class Solution {
public:
    int ans = 0;
    int solve(int i, vector<int>& cost, int n){
        if(i>=n){
            return 0;
        }
        int l = solve(2*i+1,cost,n);
        int r = solve(2*i+2,cost,n);
        ans += abs(l-r);

        return cost[i]+max(l,r);
    }
    int minIncrements(int n, vector<int>& cost) {
        solve(0,cost,n);
        return ans;
    }
};