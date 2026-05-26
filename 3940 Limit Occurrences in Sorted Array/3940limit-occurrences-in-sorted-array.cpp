class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> num(101,0);
        for(int i=0; i<n; i++){
            num[nums[i]]++;
        }
        for(int i=0; i<101; i++){
            if(num[i]>k) num[i]=k;
        }
        for(int i=0; i<101; i++){
            int val = num[i];
            for(int j=1; j<=val; j++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};