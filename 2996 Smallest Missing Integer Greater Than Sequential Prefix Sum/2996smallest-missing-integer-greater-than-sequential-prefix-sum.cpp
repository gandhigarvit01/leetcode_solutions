class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int lps = 0; // longest prefix sum
        lps += nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]==1) lps += nums[i];
            else break;
        }
        int x = lps;
        set<int> st;
        for(int num : nums) st.insert(num);
        while(st.find(x)!=st.end()) x++;
        return x;
    }
};