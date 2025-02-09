class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long j=0,k=0;
        int n=nums.size();
        long long l= (n*(n-1LL))/2;
        unordered_map<long long,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]-i]++;
        }
        for(auto it:mpp){
            if(it.second>1){
                j= it.second;
                k += (j*(j-1LL))/2;
            }
        }
        return l-k;
    }
};