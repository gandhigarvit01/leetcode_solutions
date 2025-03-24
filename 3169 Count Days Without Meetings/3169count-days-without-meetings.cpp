class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int c=0, k=0;
        int n=meetings.size();
        c += meetings[0][1]-meetings[0][0]+1;
        k = meetings[0][1]; 
        for(int i=1; i<n; i++){
            if(meetings[i][0]>k){
                c += meetings[i][1]-meetings[i][0]+1;
                k = meetings[i][1];
            }
            else{
                if(meetings[i][1]>k){
                    c += meetings[i][1]-k;
                    k = meetings[i][1];
                }
            }
        }
        return days-c;
    }
};