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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        int currlevelsum = 0;
        int nextlevelsum = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                currlevelsum = nextlevelsum;
                nextlevelsum = 0;
            }
            else{
                temp->val = currlevelsum - temp->val;
                if(temp->left!=NULL && temp->right!=NULL){
                    int sum = temp->left->val + temp->right->val;
                    temp->left->val = sum;
                    temp->right->val = sum;
                    nextlevelsum += sum;
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else if(temp->left!=NULL){
                    nextlevelsum += temp->left->val;
                    q.push(temp->left);
                } 
                else if(temp->right!=NULL){
                    nextlevelsum += temp->right->val;
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};