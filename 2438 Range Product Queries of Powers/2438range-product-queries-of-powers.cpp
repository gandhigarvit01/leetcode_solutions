class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        int mod = 1e9+7;
        vector<int> powers; 
        for(int i=0; i<31; i++){
            if((n & (1<<i))!=0){
                powers.push_back(1<<i);
            }
        }
        vector<int> ans(m,1);
        for(int i=0; i<m; i++){
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                ans[i] = (1LL*ans[i]*powers[j])%mod;
            }
        }
        return ans;
    }
};