/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string preorder(TreeNode* root){
        if(root==NULL) return "N";
        string l = preorder(root->left);
        string r = preorder(root->right);
        string res = to_string(root->val) + "," + l + "," + r;
        return res;
    }
    string serialize(TreeNode* root) {
        string ans = preorder(root);
        for(int i=0; i<ans.size(); i++){
            cout << ans[i];
        }
        return ans;
    }

    // Decodes your encoded data to tree
    int n;
    int idx;
    TreeNode* build(string& s){
        if(idx>=n) return NULL;
        if(s[idx]=='N'){
            idx++;
            return NULL;
        }
        int sign = 1;
        if(s[idx]=='-'){
            idx++;
            sign = -1;
        }
        int val = 0;
        while(s[idx]!=','){
            val = val*10 + s[idx]-'0';
            idx++;
        }
        val = val*sign;
        TreeNode* root = new TreeNode(val);
        idx++;
        root->left = build(s);
        idx++;
        root->right = build(s);
        return root;
    }
    TreeNode* deserialize(string data) {
        n = data.size();
        idx = 0;
        return build(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));