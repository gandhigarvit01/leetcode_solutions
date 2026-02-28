class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        mpp.clear();
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        int x,y;
        x = nums[0];
        int freq_x = mpp[x];
        for(int i=0; i<n; i++){
            y = nums[i];
            if(mpp[y]!=freq_x){
                return {x,y};
            }
        }
        return {-1,-1};
    }
};