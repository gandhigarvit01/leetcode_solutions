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
    vector<TreeNode*> solve(vector<int>& vec, int l, int r){
        vector<TreeNode*> res;
        if(l>r) return {NULL};
        for(int i=l; i<=r; i++){
            vector<TreeNode*> res1 = solve(vec,l,i-1);
            vector<TreeNode*> res2 = solve(vec,i+1,r);
            for(int j=0; j<res1.size(); j++){
                for(int k=0; k<res2.size(); k++){
                    TreeNode* root = new TreeNode(vec[i]);
                    root->left = res1[j];
                    root->right = res2[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = i+1;
        }
        return solve(vec,0,n-1);
    }
};