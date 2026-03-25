class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        vector<vector<long long>> pre_sum(m, vector<long long>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total += grid[i][j];
                pre_sum[i][j] = grid[i][j];
                if(i>0) pre_sum[i][j] += pre_sum[i-1][j];
                if(j>0) pre_sum[i][j] += pre_sum[i][j-1];
                if(i>0 && j>0) pre_sum[i][j] -= pre_sum[i-1][j-1];
            }
        }
        for(int i=0; i<m; i++){
            if(pre_sum[i][n-1]==total-pre_sum[i][n-1]) return true;
        }
        for(int j=0; j<n; j++){
            if(pre_sum[m-1][j]==total-pre_sum[m-1][j]) return true;
        }
        return false;
    }
};