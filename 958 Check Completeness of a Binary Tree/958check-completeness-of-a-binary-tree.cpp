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
    bool isCompleteTree(TreeNode* root) {
        vector<unsigned long long> v;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});

        while(q.size()>0){
            auto temp = q.front().first;
            unsigned long long index = q.front().second;
            q.pop();

            v.push_back(index);
            if(temp->left){
                q.push({temp->left,2*index+1});
            }
            if(temp->right){
                q.push({temp->right,2*index+2});
            }
        } 
        return v.back() == v.size()-1;
    }
};