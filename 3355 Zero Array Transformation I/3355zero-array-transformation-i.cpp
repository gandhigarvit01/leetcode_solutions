class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> vec(n,0);
        for(auto &v : queries){
            int start = v[0];
            int end = v[1]+1;
            vec[start] -= 1;
            if(end<n){
                vec[end] += 1;
            }
        }
        for(int i=1; i<n; i++){
            vec[i] += vec[i-1];
        }
        for(int i=0; i<n; i++){
            if(nums[i]+vec[i]>0){
                return false;
            }
        }
        return true;
    }
};