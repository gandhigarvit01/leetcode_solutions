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
    vector<long long> v;
    long long sum = 0;
    void solve(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(q.size()>0){
            TreeNode* temp = q.front();
            q.pop();

            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                v.push_back(sum);
                sum = 0;
            }
            else{
                sum += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        solve(root);
        sort(v.begin(), v.end(), greater<long long>());
        if(k<=v.size()){
            return v[k-1];
        }
        return -1;
    }
};