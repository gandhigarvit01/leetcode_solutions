class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long time = 0;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int m = intervals.size();
        for(int i=0; i<m; i++){
            start = max(start, intervals[i][0]);
            int end = intervals[i][1];
            if(end>=start) time += (end-start+1);
            start = max(start,end+1);
        }
        long long ans = 0;
        int bulbs = (brightness/3);
        if(brightness%3!=0) bulbs++;
        ans = 1LL*time*bulbs;
        return ans;
    }
};