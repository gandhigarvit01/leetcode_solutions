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
    int min_op(vector<int> vec){
        vector<int> sorted_vec(vec.begin(),vec.end());
        sort(sorted_vec.begin(),sorted_vec.end());
        unordered_map<int,int> mpp;
        int n = vec.size();
        for(int i=0; i<n; i++){
            mpp[vec[i]] = i;
        }
        int swaps = 0;
        for(int i=0; i<n; i++){
            if(vec[i]!=sorted_vec[i]){
                int idx = mpp[sorted_vec[i]];
                swap(vec[i],vec[idx]);
                swaps++;
                mpp[vec[i]] = i;
                mpp[vec[idx]] = idx;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> vec;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                ans += min_op(vec);
                vec.clear();
            }
            else{
                vec.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
        return ans;
    }
};