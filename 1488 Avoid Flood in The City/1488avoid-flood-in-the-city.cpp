class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> lastRain;  // lake -> last day it was filled
        set<int> dryDays; // sorted days where we can dry

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1;
                if (lastRain.count(lake)) {
                    // need to dry lake before today
                    int prev = lastRain[lake];
                    auto it = dryDays.upper_bound(prev);
                    if (it == dryDays.end()) return {}; // no valid dry day
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                lastRain[lake] = i;
            } else {
                dryDays.insert(i); // mark as available dry day
            }
        }
        return ans;
    }
};
