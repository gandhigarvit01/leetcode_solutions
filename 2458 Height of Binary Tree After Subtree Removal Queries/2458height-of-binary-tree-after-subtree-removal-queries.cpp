/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, multiset<pair<int,int>>> mp1; /// level -> {height,node};
    unordered_map<int, pair<int,int>> mp2; // node -> (level,height)
    int level_heights(TreeNode* root, int depth){
        if(root==NULL){
            return depth-1;
        }
        int l = level_heights(root->left,depth+1);
        int r = level_heights(root->right,depth+1);
        int ht = max(l,r);
        mp2[root->val] = {depth,ht};
        mp1[depth].insert({ht,root->val});
        return ht;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int height = level_heights(root,0);
        int n = queries.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int node = queries[i];
            int node_level = mp2[node].first;
            int node_ht = mp2[node].second;
            mp1[node_level].erase({node_ht,node});
            if(!mp1[node_level].empty()){
                auto it = mp1[node_level].rbegin();
                ans[i] = (*it).first;
            }
            else{
                ans[i] = node_level - 1;
            }
            mp1[node_level].insert({node_ht,node});
        }
        return ans;
    }
};