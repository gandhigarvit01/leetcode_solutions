class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();    
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int idx = ch-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool solve(string& word, int i, TrieNode* curr){
        if(i==word.size()){
            return curr->isEnd;
        }
        if(word[i]=='.'){
            for(int j=0; j<26; j++){
                if(curr->children[j]!=NULL){
                    if(solve(word, i+1, curr->children[j])) return true;
                }
            }
            return false;
        }
        else{
            int idx = word[i]-'a';
            if(curr->children[idx]==NULL) return false;
            return solve(word, i+1, curr->children[idx]);
        }
        return false;
    }

    bool search(string word) {
        return solve(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */