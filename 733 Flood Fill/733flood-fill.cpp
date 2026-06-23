class Solution {
public:
    int m,n;
    int di[4] = {0,-1,0,1};
    int dj[4] = {-1,0,1,0};
    void dfs(int i, int j, int col, vector<vector<int>>& image, int color, vector<vector<bool>>& visited){
        if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=col || visited[i][j]) return;
        visited[i][j] = true;
        image[i][j] = color;
        for(int k=0; k<4; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            dfs(ni,nj,col,image,color,visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int col = image[sr][sc];
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        dfs(sr,sc,col,image,color,visited);
        return image;
    }
};