class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        auto lambda = [](pair<char,int>& p1, pair<char,int>& p2){
            if(p1.first==p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(lambda)>
        pq(lambda); // MIN_HEAP
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                s[pq.top().second] = '*';
                pq.pop();
            }
            else{
                pq.push({s[i],i});
            }
        }
        string k = "";
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                k.push_back(s[i]);
            }
        }
        return k;
    }
};