class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        multiset<int> st;
        long long ans = 0;
        int i = 0, j = 0;
        while(j<n){
            st.insert(nums[j]);
            while((*st.rbegin()-*st.begin())*st.size()>k){
                st.erase(st.find(nums[i]));
                i++;
            }
            ans += st.size();
            j++;
        }
        return ans;
    }
};
