class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;
        for(int x : nums){
            long long cur = x;
            while(!st.empty() && st.back() == cur){
                cur += st.back();
                st.pop_back();
            }
            st.push_back(cur);
        }
        return st;
    }
};
