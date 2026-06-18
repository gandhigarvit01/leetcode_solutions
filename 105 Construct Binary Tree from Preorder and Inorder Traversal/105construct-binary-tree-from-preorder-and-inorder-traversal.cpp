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
    TreeNode* build(vector<int>& preorder, int l1, int e1, vector<int>& inorder, int l2, int e2){
        if(l1>e1) return NULL;
        int val = preorder[l1];
        TreeNode* root = new TreeNode(preorder[l1]);
        int idx = -1;
        for(int i=l2; i<=e2; i++){
            if(inorder[i]==val){
                idx = i;
                break;
            }
        }
        int elmts = idx-l2;  // elements in left
        root->left = build(preorder,l1+1,l1+elmts,inorder,l2,idx-1);
        root->right = build(preorder,l1+elmts+1,e1,inorder,idx+1,e2);
        return root;
    }  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, 0, n-1, inorder, 0, n-1); 
    }
};