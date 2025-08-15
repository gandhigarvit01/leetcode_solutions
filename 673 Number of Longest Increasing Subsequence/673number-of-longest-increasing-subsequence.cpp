class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> vec(n,{1,1});
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(vec[i].first<vec[j].first+1){
                        vec[i].first = vec[j].first+1;
                        vec[i].second = vec[j].second;
                    }
                    else if(vec[i].first == vec[j].first+1){
                        vec[i].second += vec[j].second;
                    }
                }
            }
        }
        int maxi = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi,vec[i].first);
        }
        for(int i=0; i<n; i++){
            if(vec[i].first==maxi){
                ans += vec[i].second;
            }
        }
        return ans;
    }
};