class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int ans = 0;
        int curr = INT_MIN;
        sort(pairs.begin(),pairs.end());
        for(int i=0; i<n; i++){
            if(pairs[i][0] > curr){
                ans++;
                curr = pairs[i][1];
            }
            else{
                if(pairs[i][1] < curr){
                    curr = pairs[i][1];
                }
            }
        }
        return ans;
    }
};