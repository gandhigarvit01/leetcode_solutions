class Solution {
public:
    pair<long long, long long> dp[16][2][3][10][10];
    pair<long long, long long> solve(string& s, int pos, bool tight, int start, int sld, int ld){
        if(pos==s.size()){
            return {0,1};
        }
        if(dp[pos][tight][start][sld][ld].first!=-1) return dp[pos][tight][start][sld][ld];
        int ul = tight ? s[pos]-'0' : 9;
        long long ans = 0;
        long long nums = 0;
        for(int i=0; i<=ul; i++){
            int n_start = 0;
            if(start==0 && i!=0) n_start++;
            if(start!=0) n_start = start+1;
            if(n_start>1) n_start=2;
            auto p = solve(s, pos+1, (tight && i==ul), n_start, ld, i);
            ans += p.first;
            nums += p.second;
            if(start>1 && ((ld>sld && ld>i) || (ld<sld && ld<i))) ans += p.second;
        }
        return dp[pos][tight][start][sld][ld] = {ans, nums};
    }
    long long totalWaviness(long long num1, long long num2) {
        string s1 = to_string(num1-1);
        string s2 = to_string(num2);
        fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + 16*2*3*10*10, make_pair(-1LL,-1LL));
        auto p1 = solve(s1,0,1,0,0,0);
        fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + 16*2*3*10*10, make_pair(-1LL,-1LL));
        auto p2 = solve(s2,0,1,0,0,0);
        return p2.first - p1.first;
    }
};