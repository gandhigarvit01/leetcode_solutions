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
    int ans = 0;
    pair<int,int> avg(TreeNode* root){
        if(root==NULL) return {0,0};
        auto l = avg(root->left);
        auto r = avg(root->right);
        int sum = l.first + r.first + root->val;
        int nodes = l.second + r.second + 1;
        if(root->val == sum/nodes) ans++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        auto p = avg(root);
        return ans;
    }
};