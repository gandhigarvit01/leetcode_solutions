class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> v(n,-1);
        for(int i=0; i<n;){
            if(st.empty()){
                st.push({temperatures[i],i});
                i++;
            }
            else if(temperatures[i]>st.top().first){
                while(!st.empty() && temperatures[i]>st.top().first){
                    v[st.top().second] = i-st.top().second;
                    st.pop();
                }
                st.push({temperatures[i],i});
                i++;
            }
            else if(temperatures[i]<=st.top().first){
                st.push({temperatures[i],i});
                i++;
            }
        }
        while(!st.empty()){
            v[st.top().second]=0;
            st.pop();
        }
        return v;
    }
};