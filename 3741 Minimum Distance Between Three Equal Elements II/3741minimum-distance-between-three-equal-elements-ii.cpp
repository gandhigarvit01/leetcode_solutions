class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it : mpp){
            int m = it.second.size();
            if(m>=3){
                int l=0;
                while(l<=m-3){
                    int i = it.second[l];
                    int j = it.second[l+1];
                    int k = it.second[l+2];
                    int curr = abs(i-j) + abs(j-k) + abs(i-k);
                    ans = min(ans, curr);
                    l++;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};