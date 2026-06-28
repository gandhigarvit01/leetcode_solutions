class TrieNode{
    public:
    TrieNode* children[2];

    TrieNode(){
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

void insert(TrieNode* curr, int num){
    for(int i=31; i>=0; i--){
        int bit = (num>>i)&1;
        if(curr->children[bit]==nullptr){
            curr->children[bit] = new TrieNode();
        }
        curr = curr->children[bit];
    }
}

int ans;
void search(TrieNode* curr, int num){
    int res = 0;
    for(int i=31; i>=0; i--){
        int bit = (num>>i)&1;
        int opp = 1-bit;
        if(curr->children[opp]!=nullptr){
            curr = curr->children[opp];
            res = res | (1<<i);
        }
        else{
            curr = curr->children[bit];
        }
    }
    ans = max(ans, res);
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        ans = 0;
        TrieNode* root = new TrieNode();
        int n = nums.size();
        for(int i=0; i<n; i++){
            insert(root, nums[i]);
        }
        for(int i=0; i<n; i++){
            search(root, nums[i]);
        }
        return ans;
    }
};