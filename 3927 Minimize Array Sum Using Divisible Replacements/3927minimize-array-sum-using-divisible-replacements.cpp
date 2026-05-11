class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = nums[i];
        }
        for(int i=0; i<n; i++){
            int val = nums[i];
            for(int j=1; j*j<=val; j++){
                if(val%j==0){
                    if(st.find(j)!=st.end()) ans[i] = min(ans[i],j);
                    int k = val/j;
                    if(st.find(k)!=st.end()) ans[i] = min(ans[i],k);
                }
            }
        }
        long long res = 0;
        for(int i=0; i<n; i++){
            res += ans[i];
        }
        return res;
    }
};