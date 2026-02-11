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
    vector<TreeNode*> ans;
    unordered_map<string,int> mpp;
    string duplicate(TreeNode* root){
        if(root==NULL) return "#";
        string l = duplicate(root->left);
        string r = duplicate(root->right);
        string k = l + ',' + r + ',' + to_string(root->val);
        if(mpp[k]==1){
            ans.push_back(root);
        }
        mpp[k]++;
        return k;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        duplicate(root);
        return ans;
    }
};