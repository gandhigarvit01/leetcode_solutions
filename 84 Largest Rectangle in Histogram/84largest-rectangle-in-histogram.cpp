class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> st;
        int i=1;
        int Max=0,curr=0,k=0,j=0,l=0;
        while(i<=n){
            if(st.empty())
            {
                st.push({heights[i-1],i});
            }
            else if(st.top().first<=heights[i-1])
            {
                st.push({heights[i-1],i});
            }
            else if(st.top().first>heights[i-1])
            {
                k=0;
                while(!st.empty() && st.top().first>heights[i-1])
                {
                    j = st.top().second;
                    l = st.top().first;
                    st.pop();
                    if(!st.empty())
                    k += j-st.top().second;
                    else
                    k += j;
                    curr = l*k;
                    Max = max(curr,Max);
                }
                st.push({heights[i-1],i});
            }
            i++;
        }
        k=0;
        while(!st.empty()){
            j = st.top().second;
            l = st.top().first;
            st.pop();
            if(!st.empty())
            k += j-st.top().second;
            else
            k += j;
            curr = l*k;
            Max = max(curr,Max);
        }
        return Max;
    }
};