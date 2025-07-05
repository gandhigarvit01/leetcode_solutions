class Solution {
public:
    int n;
    int dp[50001];
    int getnext(vector<vector<int>>& vec, int l, int target){
        int r = n-1;
        int result = n+1;
        while(l <= r){
            int mid = l+(r-l)/2;

            if(vec[mid][0]>=target){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& vec, int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int next = getnext(vec, i+1, vec[i][1]);
        int take = vec[i][2] + solve(vec, next);
        int nottake = solve(vec,i+1);

        return dp[i] = max(take, nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> vec(n, vector<int>(3));
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                vec[i][0] = startTime[i];
                vec[i][1] = endTime[i];
                vec[i][2] = profit[i];
            }
        }
        memset(dp, -1, sizeof(dp));
        sort(vec.begin(),vec.end());
        return solve(vec, 0);
    }
};