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
    void arrange(vector<TreeNode*>& vec){
        int n = vec.size();
        int l=0, r=n-1;
        while(l<r){
            int temp = vec[l]->val;
            vec[l]->val = vec[r]->val;
            vec[r]->val = temp;
            l++;
            r--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        vector<TreeNode*> vec;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                level++;
                if(!q.empty()) q.push(NULL);
                if(level%2==0) arrange(vec);
                vec.clear();
            }
            else{
                vec.push_back(temp);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
        return root;
    }
};