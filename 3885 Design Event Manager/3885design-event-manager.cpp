class EventManager {
public:
    class Compare {
    public:
        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) {
            if(p1.first == p2.first)
                return p1.second > p2.second; 
            return p1.first < p2.first; 
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    unordered_map<int,int> mpp;
    EventManager(vector<vector<int>>& events) {
        int n = events.size();
        for(int i=0; i<n; i++){
            pq.push({events[i][1],events[i][0]});
            mpp[events[i][0]] = events[i][1];
        }
    }
    void updatePriority(int eventId, int newPriority) {
        mpp[eventId] = newPriority;
        pq.push({newPriority,eventId});
    }
    int pollHighest() {
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int event = p.second;
            int priority = p.first;
            if(mpp[event]==priority){
                mpp[event] = -1;
                return event;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */