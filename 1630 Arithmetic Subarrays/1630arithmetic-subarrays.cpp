class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m,true);
        for(int i=0; i<m; i++){
            int left = l[i];
            int right = r[i];
            vector<int> temp;
            for(int j=left; j<=right; j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int size = right-left+1;
            int diff = temp[1]-temp[0];
            for(int k=0; k<size-1; k++){
                if(temp[k+1]-temp[k]!=diff){
                    ans[i] = false;
                }
            }
        }
        return ans;
    }
};