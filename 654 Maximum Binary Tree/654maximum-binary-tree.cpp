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
    TreeNode* solve(vector<int> &nums, int l , int r){
        if(l>r){
            return NULL;
        }
         int k = INT_MIN;
         int m = -1;
        for(int i=l; i<=r; i++){
            if(nums[i]>k){
                k=nums[i];
                m=i;
            }
        }
        TreeNode* temp = new TreeNode(k);
        temp->left = solve(nums,l,m-1);
        temp->right = solve(nums,m+1,r);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n-1;
        TreeNode* tem = solve(nums, l, r);
        return tem;
    }
};