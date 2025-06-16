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
    int k = INT_MIN;
    int solve(TreeNode* root, map<int,int> &mp){
        if(root==NULL){
            return 0;
        }
        int a = solve(root->left,mp) + solve(root->right,mp) + root->val;
        mp[a]++;
        k = max(k,mp[a]);
        return a;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> v;
        map<int,int> mp;
        int l = solve(root, mp);
        for(auto it : mp){
            if(it.second == k){
                v.push_back(it.first);
            }
        }
        return v;
    }
};