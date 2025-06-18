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
    int k;
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int l, int r){
        k--;   
        if(l>r){
            k++;
            return NULL;
        }    
        TreeNode* root;
        int p = -1;
        for(int i=l; i<=r; i++){
            if(inorder[i]==postorder[k]){
                p = i;
            }
        }
        root = new TreeNode(postorder[k]);
        root->right = solve(postorder,inorder,p+1,r);
        root->left = solve(postorder,inorder,l,p-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        k = inorder.size();
        TreeNode* q = solve(postorder,inorder,0,inorder.size()-1);
        return q;
    }
};