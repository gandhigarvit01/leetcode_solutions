class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        long long ans = 0;
        if(n==1){
            for(int i=0; i<m; i++){
                ans += units[i][0];
            }
            return ans;
        }
        for(int i=0; i<m; i++){
            sort(units[i].begin(),units[i].end());
        }
        int mini = INT_MAX;
        for(int i=0; i<m; i++){
            mini = min(mini, units[i][0]);
        }
        ans += mini;
        mini = INT_MAX;
        for(int i=0; i<m; i++){
            mini = min(mini, units[i][1]);
            ans += units[i][1];
        }
        return ans-mini;
    }
};