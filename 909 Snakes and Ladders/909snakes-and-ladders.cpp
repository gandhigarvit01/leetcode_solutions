class Solution {
public:
    int n;
    pair<int,int> getCoord(int i){
        int rt = (i-1)/n;
        int rb = (n-1) - rt;
        int col = (i-1)%n;
        if((n%2==1 && rb%2==1) || (n%2==0 && rb%2==0)){
            col = (n-1) - col;
        }
        return {rb,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        q.push(1);
        int steps = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int x = q.front();
                q.pop();
                if(x == n*n) return steps;
                for(int k=1; k<=6; k++){
                    int val = x+k;
                    if(val > n*n) break;
                    pair<int,int> p = getCoord(val);
                    int r = p.first;
                    int c = p.second;
                    if(visited[r][c]) continue;
                    visited[r][c] = true;
                    if(board[r][c]==-1) q.push(val);
                    else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};