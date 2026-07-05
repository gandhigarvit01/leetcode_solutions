class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int> dp(n,0);
        for(int i=0; i<m; i++){
            for(int j=triangle[i].size()-1; j>=0; j--){
                if(j==0){
                    dp[j] += triangle[i][j]; 
                }
                else if(j==triangle[i].size()-1){
                    dp[j] = dp[j-1] + triangle[i][j];
                }
                else{
                    dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};