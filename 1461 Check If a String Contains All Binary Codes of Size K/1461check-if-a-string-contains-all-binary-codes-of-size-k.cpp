class Solution {
public:
    set<string> st; 
    bool hasAllCodes(string s, int k) {
        st.clear();
        int n = s.size();
        if(n<k) return false;
        string a = s.substr(0,k);
        st.insert(a);
        int j = k;
        while(j<n){
            a.erase(0,1);
            a += s[j];
            st.insert(a);
            j++;
        }
        int m = st.size();
        int l = pow(2,k);
        return m==l;
    }
};