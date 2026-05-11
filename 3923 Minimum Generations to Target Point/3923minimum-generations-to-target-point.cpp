class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int n = points.size();
        int a = target[0], b = target[1], c = target[2];
        set<tuple<int,int,int>> st;
        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int z = points[i][2];
            st.insert({x,y,z});
        }
        int k = 0;
        while(1){
            if(st.find({a,b,c})!=st.end()) return k;
            vector<vector<int>> vec;
            for(auto it : st){
                int x = get<0>(it);
                int y = get<1>(it);
                int z = get<2>(it);
                vec.push_back({x,y,z});
            }
            int oldsize = st.size();
            for(int i=0; i<vec.size(); i++){
                for(int j=i+1; j<vec.size(); j++){
                    int x1 = vec[i][0];
                    int y1 = vec[i][1];
                    int z1 = vec[i][2];
                    int x2 = vec[j][0];
                    int y2 = vec[j][1];
                    int z2 = vec[j][2];
                    int x = (x1+x2)/2;
                    int y = (y1+y2)/2;
                    int z = (z1+z2)/2;
                    st.insert({x,y,z});
                }
            }
            if(st.size()==oldsize) break;
            k++;
        }
        if(st.find({a,b,c})!=st.end()) return k;
        return -1;
    }
};