class Solution {
public:
    int n;
    int dp1[1005][1005], dp2[1005][1005];
    int solveforchild2(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& fruits){
        if(i==n-1 && j==n-1){
            return 0;
        }
        if(dp1[i][j]!=-1){
            return dp1[i][j];
        }
        int path1=0, path2=0, path3=0;
        if(!visited[i][j]){
            visited[i][j] = true;
            path1 = path2 = path3 = fruits[i][j];
        }
        if(j-1 >= i+1){
            path1 += solveforchild2(i+1,j-1,visited,fruits);
        }
        if(j >= i+1){
            path2 += solveforchild2(i+1,j,visited,fruits);
        }
        if((j >= i) && j<n-1){
            path3 += solveforchild2(i+1,j+1,visited,fruits);
        }
        visited[i][j] = false;
        return dp1[i][j] = max(path1,max(path2,path3));
    }
    int solveforchild3(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& fruits){
        if(i==n-1 && j==n-1){
            return 0;
        }
        if(dp2[i][j]!=-1){
            return dp2[i][j];
        }
        int path1=0, path2=0, path3=0;
        if(!visited[i][j]){
            visited[i][j] = true;
            path1 = path2 = path3 = fruits[i][j];
        }
        if(i-1 >= j+1){
            path1 += solveforchild3(i-1,j+1,visited,fruits);
        }
        if(i >= j+1){
            path2 += solveforchild3(i,j+1,visited,fruits);
        }
        if((i >= j) && i<n-1){
            path3 += solveforchild3(i+1,j+1,visited,fruits);
        }
        visited[i][j] = false;
        return dp2[i][j] = max(path1,max(path2,path3));
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int total = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            total += fruits[i][i];
            visited[i][i] = true;
        }
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        vector<vector<bool>> visited2 = visited;
        vector<vector<bool>> visited3 = visited;
        total += solveforchild2(0,n-1,visited2,fruits);
        total += solveforchild3(n-1,0,visited3,fruits);
        return total;
    }
};