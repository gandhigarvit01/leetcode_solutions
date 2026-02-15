class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp1;
        unordered_map<int,vector<int>> mpp2;
        for(int i=0; i<n; i++){
            mpp1[nums[i]]++;
        }
        for(auto& it : mpp1){
            mpp2[it.second].push_back(it.first); 
        }
        for(int i=0; i<n; i++){
            int val = mpp1[nums[i]];
            if(mpp2[val].size()==1) return nums[i];
        }
        return -1;
    }
};