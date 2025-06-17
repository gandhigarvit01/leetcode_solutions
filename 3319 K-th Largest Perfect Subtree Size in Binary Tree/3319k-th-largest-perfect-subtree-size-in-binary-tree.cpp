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
    int m=0, n=-1;
    vector<int> v;
    int solve(TreeNode* root, int k){
        if(root==NULL){
            return 0;
        }
        int l = solve(root->left, k);
        int r = solve(root->right, k);
        if(l==r){
            v.push_back(l+r+1);
        }
        if(l==r){
            return l+r+1;
        }     
        else if(l==-1 || r==-1 || l!=r){
            return -1;
        }
        return 0;     
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve (root,k);
        sort(v.begin(), v.end(), greater<int>());
        if(k<=v.size()){
            return v[k-1];
        }
        else{
            return -1;
        }
    }
};