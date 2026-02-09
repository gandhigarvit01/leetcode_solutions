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
    vector<int> elements;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        elements.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* build(vector<int>& elements, int start, int end){
        if(start>end){
            return NULL;
        }
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(elements[mid]);
        root->left = build(elements,start,mid-1);
        root->right = build(elements,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root){
        elements.clear();
        inorder(root);
        int n = elements.size();
        return build(elements,0,n-1);
    }
};