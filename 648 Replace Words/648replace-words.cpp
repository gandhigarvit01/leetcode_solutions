class TrieNode{
    public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
};

void insert(TrieNode* curr, string& word){
    for(char ch : word){
        int idx = ch - 'a';
        if(curr->children[idx]==NULL){
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}

string find_prefix(TrieNode* curr, string& word){
    string k = "";
    for(char ch : word){
        int idx = ch - 'a';
        if(curr->children[idx]==NULL){
            return "";
        }
        curr = curr->children[idx];
        k.push_back(ch);
        if(curr->isEnd) return k;
    }
    return "";
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        int m =  dictionary.size();
        TrieNode* root = new TrieNode();
        for(string& word : dictionary){
            insert(root, word);
        }

        int n = sentence.size();
        string ans = "";
        int idx = 0;
        while(idx < n){
            string word = "";
            while(idx<n && sentence[idx]!=' '){
                word.push_back(sentence[idx]);
                idx++;
            }
            string s = find_prefix(root, word);
            ans += s.empty()? word: s;
            ans.push_back(' ');
            idx++;
        }
        ans.pop_back();
        return ans;
    }
};