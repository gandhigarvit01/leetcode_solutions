class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> nums2 = nums;
        vector<int> ans;
        int n = nums.size();
        sort(nums2.begin(),nums2.end());
        unordered_map<int,int> mpp;
        for(int i=n-1; i>=0 && k>0; i--){
            mpp[nums2[i]]++;
            k--;
        }
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                if(mpp[nums[i]]>0){
                    ans.push_back(nums[i]);
                    mpp[nums[i]]--;
                }
            }
        }
        return ans;
    }
};