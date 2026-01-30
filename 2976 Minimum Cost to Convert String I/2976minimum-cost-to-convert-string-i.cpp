class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        vector<vector<pair<int,int>>> adj(26);
        int m = cost.size();
        for(int i=0; i<m; i++){
            adj[original[i]-'a'].push_back({cost[i],changed[i]-'a'});
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(source[i]==target[i]){
                continue;
            }
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            dist[source[i]-'a'][source[i]-'a'] = 0;
            pq.push({0,source[i]-'a'});
            while(!pq.empty()){
                pair<long long,int> p = pq.top();
                pq.pop();
                long long d = p.first;
                int node = p.second;

                for(auto& e : adj[node]){
                    int v = e.second;
                    int w = e.first;
                    if(d+w<dist[source[i]-'a'][v]){
                        dist[source[i]-'a'][v] = d + w;
                        pq.push({dist[source[i]-'a'][v],v});
                    }
                }
            }
            if(dist[source[i]-'a'][target[i]-'a']==LLONG_MAX){
                return -1;
            }
            ans += dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};