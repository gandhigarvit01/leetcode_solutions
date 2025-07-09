class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[tasks[i]]++;
        }
        int total = 0;
        for(auto it : mpp){
            if(it.second==1){
                return -1;
            }
            else if(it.second%3==0){
                total += it.second/3;
            }
            else{
                total += it.second/3;
                total += 1;
            }
        }
        return total;
    }
};