class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            arr[i] ^= arr[i-1];
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            int l = queries[i][0]-1;
            int r = queries[i][1];
            int res = arr[r];
            if(l>=0) res ^= arr[l];
            ans[i] = res;
        }
        return ans;
    }
};