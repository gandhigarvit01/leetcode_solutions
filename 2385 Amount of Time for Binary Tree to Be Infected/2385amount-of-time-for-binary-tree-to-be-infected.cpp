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
    pair<int,int> ht(TreeNode* root, int start){
        if(root==NULL){
            return {0,0};
        }
        auto l = ht(root->left,start);
        auto r = ht(root->right,start);
        if(root->val==start){
            ans = max(ans,max(l.first,r.first));
            return {max(l.first,r.first)+1,1};
        }
        if(r.second>0){
            ans = max(ans,max(l.first+r.second,r.first-r.second));
            return {max(l.first,r.first)+1,r.second+1};
        }
        if(l.second>0){
            ans = max(ans,max(l.first-l.second,r.first+l.second));
            return {max(l.first,r.first)+1,l.second+1};
        }
        return {max(l.first,r.first)+1,0};
    }
    int amountOfTime(TreeNode* root, int start) {
        auto p = ht(root,start);
        return ans;
    }
};