class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n,0);
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            while(!st.empty() && curr > st.top()){
                st.pop();
                ans[i]++;
            }
            if(!st.empty()) ans[i]++;
            st.push(curr);
        }
        return ans;
    }
};