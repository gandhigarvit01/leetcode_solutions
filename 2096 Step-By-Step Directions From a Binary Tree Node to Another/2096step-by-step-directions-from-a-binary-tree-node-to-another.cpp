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
    string s,t,k;
    void path(TreeNode* root, int startValue, int destValue){
        if(root==NULL) return;
        if(root->val == startValue) s=k;
        if(root->val == destValue) t=k;
        k.push_back('L');
        path(root->left,startValue,destValue);
        k.pop_back();
        k.push_back('R');
        path(root->right,startValue,destValue);
        k.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        path(root,startValue,destValue);
        int n = s.size();
        int m = t.size();
        string ans;
        int lca_idx = n;
        for(int i=0; i<n; i++){
            if(s[i]!=t[i]){
                lca_idx = i;
                break;
            }
        }
        for(int i=lca_idx; i<n; i++){
            ans.push_back('U');
        }
        for(int i=lca_idx; i<m; i++){
            ans.push_back(t[i]);
        }
        return ans;
    }
};