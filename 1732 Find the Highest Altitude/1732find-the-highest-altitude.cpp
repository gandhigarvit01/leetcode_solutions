class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        for(int i=1; i<n; i++){
            gain[i] += gain[i-1];
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(ans, gain[i]);
        }
        return ans<0?0:ans;
    }
};