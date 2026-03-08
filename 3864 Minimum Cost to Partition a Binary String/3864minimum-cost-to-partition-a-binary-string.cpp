class Solution {
public:
    int n;
    long long solve(string& s, int i, int j, int encCost, int flatCost){
        int ones = 0;
        for(int idx=i; idx<=j; idx++){
            if(s[idx]=='1') ones++;
        }
        long long cost;
        if(ones==0) cost = flatCost;
        else cost = 1LL*ones*encCost*(j-i+1);
        if((j-i+1)%2!=0) return cost;
        int mid = (i+j)/2;
        long long left = solve(s,i,mid,encCost,flatCost);
        long long right = solve(s,mid+1,j,encCost,flatCost);
        return min(cost, left+right);
    }
    long long minCost(string s, int encCost, int flatCost) {
        n = s.size();
        return solve(s,0,n-1,encCost,flatCost);
    }
};