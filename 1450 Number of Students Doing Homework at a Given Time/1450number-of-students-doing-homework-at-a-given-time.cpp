class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n=endTime.size();
        int x=0;
        for(int i=0; i<n; i++){
            if(queryTime>=startTime[i] && queryTime<=endTime[i]){
                x++;
            }
        }
        return x;
    }
};