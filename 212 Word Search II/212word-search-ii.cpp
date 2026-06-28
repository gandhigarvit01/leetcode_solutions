class Solution {
public:
    struct trienode{
        string endword;
        bool isend;
        trienode* children[26];
    };
    trienode* getnode(){
        trienode* newnode = new trienode();
        newnode->endword = "";
        newnode->isend = false;
        for(int i=0; i<26; i++){
            newnode->children[i] = NULL;
        }
        return newnode;
    }
    vector<string> ans;
    int m,n;
    void solve(vector<vector<char>>& board, int i, int j, trienode* crawl){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return;
        
        char ch = board[i][j];
        int idx = ch - 'a';
        if(crawl->children[idx]==NULL){
            return;
        }
        crawl = crawl->children[idx];
        if(crawl->isend == true){
            ans.push_back(crawl->endword);
            crawl->isend = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        
        solve(board, i, j-1, crawl);
        solve(board, i, j+1, crawl);
        solve(board, i-1, j, crawl);
        solve(board, i+1, j, crawl);

        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        trienode* root = getnode();
        int sz = words.size();
        for(int i=0; i<sz; i++){
            string word = words[i];
            string curr = "";
            trienode* crawl = root;
            for(char ch : word){
                int idx = ch - 'a';
                curr.push_back(ch);
                if(crawl->children[idx]==NULL){
                    crawl->children[idx] = getnode();
                }
                crawl = crawl->children[idx];
                crawl->endword = curr;
            }
            crawl->isend = true;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                trienode* crawl = root;
                solve(board, i, j, crawl);
            }
        }
        return ans;
    }
};