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
    void traverse(TreeNode* root, vector<int>& vec){
        if(root==NULL) return;
        if(!root->left && !root->right){
            vec.push_back(root->val);
        }
        traverse(root->left,vec);
        traverse(root->right,vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        traverse(root1,vec1);
        traverse(root2,vec2);
        return vec1==vec2;
    }
};