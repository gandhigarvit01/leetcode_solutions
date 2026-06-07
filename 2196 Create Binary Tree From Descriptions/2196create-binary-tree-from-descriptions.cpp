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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,TreeNode*> mpp;
        set<int> children;
        for(int i=0; i<n; i++){
            int par_val = descriptions[i][0];
            int child_val = descriptions[i][1];
            children.insert(child_val);
            TreeNode* par;
            TreeNode* child;
            if(mpp.find(par_val)!=mpp.end()){
                par = mpp[par_val];
            }
            else{
                par = new TreeNode(par_val);
                mpp[par_val] = par;
            }
            if(mpp.find(child_val)!=mpp.end()){
                child = mpp[child_val];
            }
            else{
                child = new TreeNode(child_val);
                mpp[child_val] = child;
            }
            if(descriptions[i][2]==1){
                par->left = child;
            }
            else{
                par->right = child;
            }
        }
        for(auto it : mpp){
            int val = it.first;
            if(children.find(val)==children.end()){
                return it.second;
            }
        }
        return NULL;
    }
};