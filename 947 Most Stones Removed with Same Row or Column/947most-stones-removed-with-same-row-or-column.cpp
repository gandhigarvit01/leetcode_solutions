class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        set<pair<int,int>> st;
        for(auto &v : stones){
            st.insert({v[0],v[1]});
        }
        queue<pair<int,int>> q;
        int ans = 0;
        int elements = 0;
        while(!st.empty()){
            q.push({st.begin()->first,st.begin()->second});
            st.erase(st.begin());
            elements = 0;
            while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            elements++;
            int i = p.first;
            int j = p.second;
            for(auto it = st.begin(); it != st.end();){
                if(it->first == i || it->second == j){ 
                q.push({it->first, it->second});
                it = st.erase(it);  
                }
                else{
                ++it;
                }
            } 
            }
            ans += elements-1;
        }
        return ans;
    }
};