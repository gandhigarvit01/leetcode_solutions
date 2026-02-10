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
    vector<int> vec;
    void paths(TreeNode* root){
        if(root==NULL) return;
        vec[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int odds = 0;
            for(int it : vec){
                if((it)%2!=0) odds++;
            }
            if(odds<=1) ans++;
        }
        paths(root->left);
        paths(root->right);
        vec[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vec.resize(10,0);
        paths(root);
        return ans;
    }
};