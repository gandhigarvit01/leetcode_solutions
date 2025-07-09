class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
    vector<pair<int, int>> paired;
    for (int i = 0; i < n; ++i)
        paired.push_back({growTime[i], plantTime[i]});
    sort(paired.rbegin(), paired.rend()); 
    for (int i = 0; i < n; ++i) {
        growTime[i] = paired[i].first;
        plantTime[i] = paired[i].second;
    }

    for(int i=1; i<n; i++){
        plantTime[i] = plantTime[i] + plantTime[i-1];
    }
    int day = INT_MIN;
    for(int i=0; i<n; i++){
        growTime[i] = growTime[i] + plantTime[i];
        day = max(day,growTime[i]);
    }
    return day;
    }
};