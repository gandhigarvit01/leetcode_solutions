class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n =dist.size();
        vector<double> time(n);
        for(int i=0; i<n; i++){
            time[i] = (double)dist[i]/speed[i];
        }
        int kills = 0;
        sort(time.begin(),time.end());
        int i = 0;
        int times = 0;
        while(i<n && time[i]>times){
            kills++;
            times++;
            i++;
        }
        return kills;
    }
};