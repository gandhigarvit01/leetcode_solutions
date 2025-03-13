class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int count=0, sum=0, curr=0;
        int n = nums.size();
        mpp[0]++;
        for(int i=0; i<n; i++){
         curr += nums[i];
         sum = curr-k;
         count += mpp[sum];
         mpp[curr]++;
        }
        return count;
    }
};