class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int k = -1;
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        for(auto it : mpp){
            if(it.first == it.second){
                if(it.first>k){
                    k = it.first;
                }
            }
        }
        return k;
    }
};