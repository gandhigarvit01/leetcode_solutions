class Solution {
public:
    int m,n;
    vector<vector<vector<long long>>> dp;
    long long solve(int i, int j, int k, vector<int>& robot, vector<vector<int>>& factory){
        if(i==n){
            return 0;
        }
        if(j==m){
            return LLONG_MAX;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long skip = LLONG_MAX, take = LLONG_MAX;
        if(j<m-1) skip = solve(i,j+1,factory[j+1][1],robot,factory);
        if(k>0) take = solve(i+1,j,k-1,robot,factory);
        if(take!=LLONG_MAX) take += abs(robot[i]-factory[j][0]);
        return dp[i][j][k] = min(skip,take);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = robot.size();
        m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        dp.assign(n+1, vector<vector<long long>>(m+1, vector<long long>(101, -1)));
        long long ans = solve(0,0,factory[0][1],robot,factory);
        return ans;
    }
};