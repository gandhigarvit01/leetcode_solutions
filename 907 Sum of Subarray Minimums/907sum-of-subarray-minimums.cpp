class Solution {
public:
    int mod = 1e9+7;
    int n;
    int solve(vector<int>& arr, int l, int r){
        if(l>r) return 0;
        int mini = INT_MAX;
        int idx;
        for(int i=l; i<=r; i++){
            if(arr[i]<mini){
                mini = arr[i];
                idx = i;
            }
        }
        int ans = 0;
        ans = (1LL*(idx-l+1)*(r-idx+1)*arr[idx])%mod;
        int left = solve(arr, l, idx-1);
        int right = solve(arr, idx+1, r);
        ans = ((ans + left)%mod + right)%mod;
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        int ans = solve(arr, 0, n-1);
        return ans;
    }
};