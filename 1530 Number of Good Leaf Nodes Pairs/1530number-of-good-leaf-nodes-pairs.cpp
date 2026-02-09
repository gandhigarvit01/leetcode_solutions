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
    unordered_map<TreeNode*,vector<TreeNode*>> adj;
    unordered_set<TreeNode*> leafnodes;
    void makegraph(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            leafnodes.insert(root);
        }
        if(root->left!=NULL){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            makegraph(root->left);
        }
        if(root->right!=NULL){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            makegraph(root->right);
        }
        return;
    }
    int countPairs(TreeNode* root, int distance) {
        makegraph(root);
        int ans = 0;
        for(auto it = leafnodes.begin(); it!=leafnodes.end(); it++){
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(*it);
            q.push(NULL);
            visited.insert(*it);
            int level = 1;
            while(!q.empty()){
                TreeNode* curr = q.front();
                q.pop();
                if(curr==NULL){
                    if(!q.empty()){
                        q.push(NULL);
                        level++;
                        if(level>distance) break;
                    }
                }
                else{
                    for(auto& v : adj[curr]){
                        if(visited.find(v)==visited.end()){
                            visited.insert(v);
                            q.push(v);
                            if(leafnodes.find(v)!=leafnodes.end()){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        return ans/2;
    }
};