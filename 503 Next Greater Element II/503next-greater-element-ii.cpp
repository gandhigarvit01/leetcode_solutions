class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n= nums.size();
        vector<int> v(n,-1);
        int i = 2*n-1;
        for(i=2*n-1; i>=0; i--){
                if(st.empty()){
                    st.push(nums[i%n]);
                    v[i%n] = -1;
                }
                else if(st.top()>nums[i%n]){
                    v[i%n] = st.top();
                    st.push(nums[i%n]);
                }
                else{
                    while(!st.empty() && st.top()<=nums[i%n]){
                        st.pop();
                    }
                    if(st.empty()) v[i%n] = -1;
                    else v[i%n] = st.top();
                    st.push(nums[i%n]);
                }
        }
        return v;
    }
};