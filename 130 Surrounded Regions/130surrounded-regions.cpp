class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                board[i][0] = 'Y';
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
                board[i][n-1] = 'Y';
                q.push({i,n-1});
            }
        }
        for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                board[0][j] = 'Y';
                q.push({0,j});
            }
            if(board[m-1][j]=='O'){
                board[m-1][j] = 'Y';
                q.push({m-1,j});
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int u = p.first;
            int v = p.second;
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};
            for(int k=0; k<4; k++){
                if(u+dx[k]>=0 && u+dx[k]<m && v+dy[k]>=0 && v+dy[k]<n && board[u+dx[k]][v+dy[k]]=='O'){
                    board[u+dx[k]][v+dy[k]] = 'Y';
                    q.push({u+dx[k],v+dy[k]});
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='Y'){
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};