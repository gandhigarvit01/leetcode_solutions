/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> mpp;
    Node* clone(Node* node){
        Node* temp = new Node(node->val);
        mpp[temp->val] = temp;
        int n = node->neighbors.size();
        temp->neighbors.resize(n);
        for(int i=0; i<n; i++){
            Node* k = node->neighbors[i];
            if(mpp.find(k->val)!=mpp.end()){
                temp->neighbors[i] = mpp[k->val];
            }
            else{
                temp->neighbors[i] = clone(node->neighbors[i]);
            }
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        return clone(node);
    }
};