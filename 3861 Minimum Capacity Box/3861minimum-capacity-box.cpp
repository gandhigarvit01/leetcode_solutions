class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1;
        int mini = INT_MAX;
        int n = capacity.size();
        for(int i=0; i<n; i++){
            if(capacity[i]<mini && capacity[i]>=itemSize){
                mini = capacity[i];
                idx = i;
            }
        }
        return idx;
    }
};