class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;
        for(auto& vec : trips){
            events.push_back({vec[1],vec[0]});
            events.push_back({vec[2],-vec[0]});
        }
        int n = events.size();
        int curr_cap = 0;
        sort(events.begin(),events.end());
        for(int i=0; i<n; i++){
            curr_cap += events[i].second;
            if(curr_cap > capacity){
                return false;
            }
        }
        return true;
    }
};