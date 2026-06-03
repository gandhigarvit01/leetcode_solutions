class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<int> landendtime;
        vector<int> waterendtime;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for(int i=0; i<n; i++){
            landendtime.push_back(landStartTime[i]+landDuration[i]);
        }
        for(int i=0; i<m; i++){
            waterendtime.push_back(waterStartTime[i]+waterDuration[i]);
        }
        sort(landendtime.begin(),landendtime.end());
        sort(waterendtime.begin(),waterendtime.end());
        int ans1 = INT_MAX;
        for(int i=0; i<m; i++){
            if(waterStartTime[i] >= landendtime[0]){
                ans1 = min(ans1, waterStartTime[i] + waterDuration[i]);
            }
            else{
                ans1 = min(ans1, landendtime[0] + waterDuration[i]);
            }
        }
        int ans2 = INT_MAX;
        for(int i=0; i<n; i++){
            if(landStartTime[i] >= waterendtime[0]){
                ans2 = min(ans2, landStartTime[i] + landDuration[i]);
            }
            else{
                ans2 = min(ans2, waterendtime[0] + landDuration[i]);
            }
        }
        return min(ans1,ans2);
    }
};