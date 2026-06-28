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

int search(TrieNode* curr, int num){
    int res = 0;
    for(int i=31; i>=0; i--){
        int bit = (num>>i)&1;
        int opp = 1-bit;
        if(curr->children[opp]!=nullptr){
            curr = curr->children[opp];
            res |= (1<<i);
        }
        else{
            curr = curr->children[bit];
        }
    }
    return res;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        TrieNode* root = new TrieNode();
        vector<int> ans(m);
        vector<vector<int>> vec;
        for(int i=0; i<m; i++){
            vector<int> res(3);
            res[0] = queries[i][1];
            res[1] = queries[i][0];
            res[2] = i;
            vec.push_back(res);
        }
        sort(nums.begin(),nums.end());
        sort(vec.begin(),vec.end());
        int idx = 0;
        for(int i=0; i<m; i++){
            int val = vec[i][0];
            int num = vec[i][1];
            int k = vec[i][2];
            while(idx<n && nums[idx]<=val){
                insert(root, nums[idx]);
                idx++;
            }
            if(idx==0) ans[k] = -1;
            else ans[k] = search(root, num);
        }
        return ans;
    }
};