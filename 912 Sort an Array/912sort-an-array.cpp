class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            mpp[nums[i]]++;
        }
        vector<int> ans;
        for(int i=mini; i<=maxi; i++){
            if(mpp.find(i)!=mpp.end()){
                int k = mpp[i];
                while(k>0){
                    ans.push_back(i);
                    k--;
                }
            }
        }
        return ans;
    }
};