class Solution {
public:
    bool isleaf(int u, unordered_map<int,vector<int>>& mpp){
        if(mpp[u].size()==0) return true;
        return false;
    }
    long long solve(int u, unordered_map<int,vector<int>>& mpp, vector<int>& baseTime){
        if(isleaf(u,mpp)){
            return (long long)baseTime[u];
        }
        long long earliest = LLONG_MAX, latest = LLONG_MIN;
        for(int v : mpp[u]){
            long long p = solve(v,mpp,baseTime);
            if(p < earliest) earliest = p;
            if(p > latest) latest = p;
        }
        long long ft = (latest - earliest) + baseTime[u] + latest;
        return ft;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        unordered_map<int,vector<int>> mpp;
        for(auto vec : edges){
            mpp[vec[0]].push_back(vec[1]);
        }
        return solve(0,mpp,baseTime);
    }
};