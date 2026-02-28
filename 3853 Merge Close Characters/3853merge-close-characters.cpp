class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;
        unordered_map<char,int> mpp;
        for(int i=0; i<n; i++){
            char curr = s[i];
            int idx = 0;
            if(st.empty()) idx = 0;
            else{
                int prev = st.top().second;
                idx = prev+1;
            }
            if(mpp.find(curr)!=mpp.end()){  // found in map
                int prev_idx = mpp[curr];
                if(idx-prev_idx <= k){
                    // do nothing
                }
                else{
                    st.push({curr,idx});
                    mpp[curr] = idx;
                }
            }
            else{ // not found
                st.push({curr,idx});
                mpp[curr] = idx;
            }
        }
        string ans = "";
        while(!st.empty()){
            char temp = st.top().first;
            st.pop();
            ans.push_back(temp);
        }
        int m = ans.size();
        int l = 0, r = m-1;
        while(l<r){
            char temp = ans[l];
            ans[l] = ans[r];
            ans[r] = temp;
            l++;
            r--;
        }
        return ans;
    }
};