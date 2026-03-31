class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int max_day = 0;
        int n = events.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            max_day = max(max_day,events[i][1]);
            mpp[events[i][0]].push_back(events[i][1]);
        }
        int ans = 0, day = 0;
        while(day<max_day){
            day++;
            if(mpp.find(day)!=mpp.end()){
                for(auto it : mpp[day]){
                    pq.push(it);
                }
            }
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};