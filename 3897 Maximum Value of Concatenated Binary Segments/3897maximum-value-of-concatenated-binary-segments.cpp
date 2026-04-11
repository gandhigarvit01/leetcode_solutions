class Solution {
public:
    int mod = 1e9+7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        int ans = 0;
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            if(nums0[i]==0){
                for(int j=0; j<nums1[i]; j++){
                    ans = ((ans*2)%mod + 1)%mod;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(nums0[i]!=0){
                vec.push_back({nums1[i],nums0[i]});
            }
        }
        sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });
        int m = vec.size();
        for(int i=0; i<m; i++){
            int l = vec[i].first;
            int r = vec[i].second;
            for(int i=0; i<l; i++){
                ans = ((ans*2)%mod + 1)%mod;
            }
            for(int i=0; i<r; i++){
                ans = (ans*2)%mod;
            }
        }
        return ans;
    }
};