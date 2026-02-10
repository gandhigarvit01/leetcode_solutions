class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n,0);
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                parent[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                parent[rightChild[i]]++;
            }
        }
        int par_0 = 0;
        int root = -1;
        for(int i=0; i<n; i++){
            if(parent[i]==0){
                par_0++;
                root = i;
            }
            if(parent[i]>1) return false;
        }
        if(par_0!=1) return false;
        
        // Now BFS from root-
        queue<int> q;
        set<int> st; // for visited check
        q.push(root);
        st.insert(root);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(leftChild[u]!=-1 && st.find(leftChild[u])==st.end()){
                q.push(leftChild[u]);
                st.insert(leftChild[u]);
            }
            if(rightChild[u]!=-1 && st.find(rightChild[u])==st.end()){
                q.push(rightChild[u]);
                st.insert(rightChild[u]);
            }
        }
        if(st.size()!=n) return false;
        return true;
    }
};