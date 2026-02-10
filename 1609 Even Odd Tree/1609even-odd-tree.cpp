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
    bool isEvenOddTree(TreeNode* root) {
        if((root->val)%2==0) return false;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        int prev = -1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                    prev = -1;
                }
            }
            else{
                if(level%2==0){
                    if((temp->val)%2==0) return false;
                    if(prev!=-1 && temp->val <= prev) return false;
                    prev = temp->val;
                }
                else{
                    if((temp->val)%2!=0) return false;
                    if(prev!=-1 && temp->val >= prev) return false;
                    prev = temp->val;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return true;
    }
};