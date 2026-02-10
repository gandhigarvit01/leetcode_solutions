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
    string ans = "~";
    void smalleststring(TreeNode* root, string k){
        if(root==NULL) return;
        k = char(root->val+'a') + k;
        if(root->left==NULL && root->right==NULL){
            if(k<ans) ans = k;
        }
        smalleststring(root->left,k);
        smalleststring(root->right,k);
    }
    string smallestFromLeaf(TreeNode* root) {
        smalleststring(root,"");
        return ans;
    }
};