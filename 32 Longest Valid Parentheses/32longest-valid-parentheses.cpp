class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int,int>> st;
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push({0,i});
            }
            else{
                if(!st.empty() && st.top().first==0){
                    st.pop();
                    if(st.empty()){
                        ans = max(ans,i+1);
                    }
                    else ans = max(ans,i-st.top().second);
                }
                else st.push({1,i});
            }
        }
        return ans;
    }
};