class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if(n==1) return s;
        unordered_map<char,int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        auto p = pq.top();
        int maxi = p.first;
        int half = (n+1)/2;
        if(maxi > half) return "";
        string k;
        while(pq.size()>=2){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            k.push_back(p1.second);
            k.push_back(p2.second);
            p1.first--, p2.first--;
            if(p1.first>0) pq.push({p1.first,p1.second});
            if(p2.first>0) pq.push({p2.first,p2.second});   
        }
        if(!pq.empty()){
            k.push_back(pq.top().second);
        }
        return k;
    }
};