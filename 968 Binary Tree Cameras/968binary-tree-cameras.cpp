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
    int solve(TreeNode* root){
        if(root==NULL) return -1;
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int k;
        if(left==-1) k = right;
        else if(right==-1) k = left;
        else{
            if(left==0){
                ans++;
                return 2;
            }
            if(right==0){
                ans++;
                return 2;
            }
            else k = max(left,right);
        }
        if(k==0){
            ans++;
            return 2;
        }
        return k-1;
    }
    int minCameraCover(TreeNode* root) {
        int a = solve(root);
        if(a==0) ans++;
        return ans;
    }
};