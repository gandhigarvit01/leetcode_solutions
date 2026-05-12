class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int time = 0;
        int n = processorTime.size();
        int m = tasks.size();
        sort(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end());
        for(int i=0; i<n; i++){
            time = max(time, processorTime[i] + tasks[m-1-4*i]);
        }
        return time;
    }
};