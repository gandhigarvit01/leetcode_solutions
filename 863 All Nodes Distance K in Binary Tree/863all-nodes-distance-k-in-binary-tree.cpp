/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void traverse(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        traverse(root);
        queue<TreeNode*> q;
        q.push(target);
        q.push(NULL);
        int level = 0;
        set<TreeNode*> st;
        st.insert(target);
        while(!q.empty()){
            TreeNode* u = q.front();
            q.pop();
            if(u==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                }
                if(level>k) break;
            }
            else{
                if(level==k) ans.push_back(u->val);
                if(u->left && st.find(u->left)==st.end()){
                    q.push(u->left);
                    st.insert(u->left);
                }
                if(u->right && st.find(u->right)==st.end()){
                    q.push(u->right);
                    st.insert(u->right);
                }
                if(parent.find(u)!=parent.end() && st.find(parent[u])==st.end()){
                    q.push(parent[u]);
                    st.insert(parent[u]);
                }
            }
        }
        return ans;
    }
};