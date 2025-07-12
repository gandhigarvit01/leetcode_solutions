class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        vector<int> freq;
        for(auto it : mpp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        int m = freq.size();
        for(int i=0; i<n; i++){
            if(k>=freq[i]){
                k -= freq[i];
                freq[i] = 0;
            }
            else{
                break;
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            if(freq[i]!=0){
                ans++;
            }
        }
        return ans;
    }
};