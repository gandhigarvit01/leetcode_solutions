class TrieNode{
    public:
    int prefixCount;
    TrieNode* children[26];

    TrieNode(){
        prefixCount = 0;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* curr, string& word){
    for(char ch : word){
        int idx = ch - 'a';
        if(curr->children[idx]==nullptr){
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
        curr->prefixCount++;
    }
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for(string& s : products){
            insert(root, s);
        }

        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        int n = products.size();
        string prefix = "";
        int m = searchWord.size();
        TrieNode* curr = root;
        int i = 0;
        int j = 0;
        while(i<m){
            vector<string> vec;
            char ch = searchWord[i];
            int idx = ch-'a';
            if(curr->children[idx]==nullptr){
                break;
            }
            else{
                curr = curr->children[idx];
                int words = min(3,curr->prefixCount);
                while(products[j][i]!=ch){
                    j++;
                }
                for(int k=j; k<j+words; k++){
                    vec.push_back(products[k]);
                }
                ans.push_back(vec);
            }
            i++;
        }
        while(i<m){
            vector<string> v;
            ans.push_back(v);
            i++;
        }
        return ans;
    }
};