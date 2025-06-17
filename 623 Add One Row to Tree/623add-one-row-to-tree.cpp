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
    void solve(TreeNode* root, int val, int depth, int vd){
        if(root==NULL){
            return;
        }
        if(vd==depth-1){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
        }
        solve(root->left,val,depth,vd+1);
        solve(root->right,val,depth,vd+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        solve(root,val,depth,1);
        return root;
    }
};