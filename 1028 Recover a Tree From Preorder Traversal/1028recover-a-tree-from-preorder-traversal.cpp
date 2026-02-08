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
    int idx = 0;
    int n;
    TreeNode* construct(string traversal, int depth){
        int val = 0;
        while(idx<n && traversal[idx]!='-'){
            val = val*10 + (traversal[idx]-'0');
            idx++;
        }
        TreeNode* root = new TreeNode(val);
        int dashes = 0;
        for(int i=idx; i<n; i++){
            if(traversal[i]=='-') dashes++;
            else break;
        }
        if(dashes==depth+1){
            idx += depth+1;
            root->left = construct(traversal,depth+1);

            dashes = 0;
            for(int i=idx; i<n; i++){
                if(traversal[i]=='-') dashes++;
                else break;
            }
            if(dashes==depth+1){
                idx += depth+1;
                root->right = construct(traversal,depth+1);
            }
        }
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        return construct(traversal,0);
    }
};