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
    int k = -1;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r){
        k++;   
        if(l>r){
            k--;
            return NULL;
        }    
        TreeNode* root;
        int p = -1;
        for(int i=l; i<=r; i++){
            if(inorder[i]==preorder[k]){
                p = i;
            }
        }
        root = new TreeNode(preorder[k]);
        root->left = solve(preorder,inorder,l,p-1);
        root->right = solve(preorder,inorder,p+1,r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder  = preorder;
        sort(inorder.begin(), inorder.end());
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};