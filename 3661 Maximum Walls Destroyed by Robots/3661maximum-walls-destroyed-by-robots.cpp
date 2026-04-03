class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int m = walls.size();
        int n = robots.size();
        sort(walls.begin(),walls.end());
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({robots[i],distance[i]});
        }
        sort(vec.begin(),vec.end());
        vector<int> right_walls(n,0);
        vector<int> left_walls(n,0);
        vector<int> common_walls(n,0);
        // walls that a robot can break to his left -
        for(int i=0; i<n; i++){
            int L = vec[i].first - vec[i].second;
            int R = vec[i].first;
            if(i-1>=0){
                L = max(L,vec[i-1].first+1);
            }
            int cnt = upper_bound(walls.begin(),walls.end(),R) - 
            lower_bound(walls.begin(),walls.end(),L);
            left_walls[i] = cnt;
        }
        // walls that a robot can break to his right -
        for(int i=0; i<n; i++){
            int L = vec[i].first;
            int R = vec[i].first + vec[i].second;
            if(i+1<n){
                R = min(R,vec[i+1].first-1);
            }
            int cnt = upper_bound(walls.begin(),walls.end(),R) - 
            lower_bound(walls.begin(),walls.end(),L);
            right_walls[i] = cnt;
        }
        // all common walls b/w lth robot and l-1th robot;
        for(int i=1; i<n; i++){
            int L = vec[i-1].first;
            int R = vec[i].first;
            int cnt = upper_bound(walls.begin(),walls.end(),R) - 
            lower_bound(walls.begin(),walls.end(),L);
            common_walls[i] = cnt;
        }
        // dp[i][0] -> max walls i robots can break if ith rob breaks left wall now;
        // dp[i][1] -> max walls i robots can break if ith rob breaks right wall now;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = left_walls[0];
        dp[0][1] = right_walls[0];
        for(int i=1; i<n; i++){
            // calculating dp[i][0]-
            int case1 = dp[i-1][0] + left_walls[i];
            int common = right_walls[i-1] + left_walls[i] - common_walls[i];
            if(common<0) common = 0; 
            int case2 = dp[i-1][1] + left_walls[i] - common;
            dp[i][0] = max(case1, case2);

            // calculating dp[i][1]-;
            case1 = dp[i-1][0] + right_walls[i];
            case2 = dp[i-1][1] + right_walls[i];
            dp[i][1] = max(case1, case2);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};