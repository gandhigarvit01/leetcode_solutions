class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> ans;
        map<long long,long long> paint;
        for(auto& vec : segments){
            paint[vec[0]] += vec[2];
            paint[vec[1]] -= vec[2];
        }
        auto it = paint.begin();
        long long event1 = it->first;
        long long color = it->second;
        paint.erase(it);
        for(auto& it : paint){
            long long event2 = it.first;
            if(color!=0)
            ans.push_back({event1,event2,color});
            color += it.second;
            event1 = event2;
        }
        return ans;
    }
};