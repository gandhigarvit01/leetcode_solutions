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
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int s1, int e1, int s2, int e2){
        if(s1>e1) return NULL;
        TreeNode* root = new TreeNode(preorder[s1]);
        if(s1==e1){
            return root;
        }
        int left_root = preorder[s1+1];
        int i;
        for(i=s2; i<=e2; i++){
            if(postorder[i]==left_root) break;
        }
        int leftsize = i-s2+1;
        root->left = construct(preorder,postorder,s1+1,s1+leftsize,s2,i);
        root->right = construct(preorder,postorder,s1+leftsize+1,e1,i+1,e2-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return construct(preorder,postorder,0,n-1,0,n-1);
    }
};