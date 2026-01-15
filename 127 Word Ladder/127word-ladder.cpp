class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int l = beginWord.size();
        int isEWpresent = 0;
        for(int i=0; i<n; i++){
            if(wordList[i]==endWord){
                isEWpresent = 1;
            }
        }
        if(isEWpresent!=1){
            return 0;
        }
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<bool> visited(n,false);
        int ans = 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();

            string word = p.first;
            int level = p.second;

            if(word==endWord){
                return level;
            }

            for(int i=0; i<l; i++){
                for(char c='a'; c<='z'; c++){
                    string newword = word;
                    newword[i] = c;
                    if(st.find(newword)!=st.end()){
                        q.push({newword,level+1});
                        st.erase(newword);
                    }
                }
            }
        }
        return 0;
    }
};