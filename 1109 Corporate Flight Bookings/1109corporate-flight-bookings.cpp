class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto &v : bookings){
            int first = v[0]-1;
            int end = v[1];
            int val = v[2];
            ans[first] += val;
            if(end<n) ans[end] -= val;
        }
        for(int i=1; i<n; i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};