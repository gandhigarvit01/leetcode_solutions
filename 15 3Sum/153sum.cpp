class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<tuple<int,int,int>> st;
        for(int i=0; i<n; i++){
            int rem = 0-nums[i];
            int l=i+1, r=n-1;
            while(l<r){
                if(nums[l]+nums[r]==rem){
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r] > rem) r--;
                else l++;
            }
        }
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back({get<0>(it), get<1>(it), get<2>(it)});
        }
        return ans;
    }
};