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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,1});
        while(!q.empty()){
            int n = q.size();
            ll mini = q.front().second;
            ll maxi = q.back().second;
            if(maxi-mini > ans){
                ans = maxi-mini;
            }
            while(n--){
                auto temp = q.front();
                q.pop();
                if(temp.first->left) q.push({temp.first->left,2*(temp.second)});
                if(temp.first->right) q.push({temp.first->right,2*(temp.second)+1});
            }
        }
        return ans+1;
    }
};