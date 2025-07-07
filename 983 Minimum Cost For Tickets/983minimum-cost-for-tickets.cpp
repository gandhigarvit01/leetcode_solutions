class Solution {
public:
    int n;
    int dp[366][400];
    int solve(vector<int>& days, vector<int>& costs, int curr_idx, int day_done){
        if(curr_idx>=n){
            return 0;
        }
        if(dp[curr_idx][day_done]!=-1){
            return dp[curr_idx][day_done];
        }
        if(day_done >= days[curr_idx]){
            return dp[curr_idx][day_done] = solve(days,costs,curr_idx+1,day_done);
        }
        else{
            int one_day = costs[0] + solve(days,costs,curr_idx+1,days[curr_idx]);
            int seven_day = costs[1] + solve(days,costs,curr_idx+1,days[curr_idx]+6);
            int thirty_day = costs[2] + solve(days,costs,curr_idx+1,days[curr_idx]+29);

            return dp[curr_idx][day_done] = min(one_day,min(seven_day,thirty_day));
        }

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0,0);
    }
};