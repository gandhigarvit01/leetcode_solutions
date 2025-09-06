class Solution {
public:
    int m,n,nonobstacles,result;
    void solve(vector<vector<int>>& grid, int count, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(count==nonobstacles){
                result++;
            }
            return;
        }
        grid[i][j] = -1;
        solve(grid,count+1,i+1,j);
        solve(grid,count+1,i,j+1);
        solve(grid,count+1,i-1,j);
        solve(grid,count+1,i,j-1);
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        nonobstacles = 0;
        int x,y;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    nonobstacles++;
                }
                if(grid[i][j]==1){
                    x = i;
                    y = j;
                    nonobstacles++;
                }
            }
        }
        result = 0;
        solve(grid,0,x,y);
        return result;
    }
};