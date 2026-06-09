class Solution {
public:
    int m,n;
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int idx){
        if(j<0 || i<0 || i>=m || j>=n || board[i][j]=='$') return false;
        if(idx==word.size()-1 && board[i][j]==word[idx]) return true;
        if(board[i][j]!=word[idx]) return false;
        bool ans = false;
        char temp = board[i][j];
        board[i][j] = '$';
        ans = ans || solve(board, word, i, j-1, idx+1);
        ans = ans || solve(board, word, i, j+1, idx+1);
        ans = ans || solve(board, word, i-1, j, idx+1);
        ans = ans || solve(board, word, i+1, j, idx+1);
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};