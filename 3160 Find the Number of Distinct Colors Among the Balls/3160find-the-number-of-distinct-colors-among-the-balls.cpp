class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n= queries.size();
        vector<int> v;
        unordered_map<int,int> ball;
        unordered_map<int,int> color;
        int l,m,k;
        for(int i=0; i<n; i++){
            l=queries[i][0];
            m=queries[i][1];
            if(ball.find(l)!=ball.end()){
                k = ball[l];
                color[k]--;
                if(color[k]==0){
                    color.erase(k);
                }
            }
            ball[l]=m;
            color[m]++;
            v.push_back(color.size());
        }
        return v;
    }
};