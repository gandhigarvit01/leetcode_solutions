class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        set<char> st;
       st.insert('a'),st.insert('e'),st.insert('i'),st.insert('o'),st.insert('u');
       st.insert('A'),st.insert('E'),st.insert('I'),st.insert('O'),st.insert('U'); 
        while(l<r){
            if(st.count(s[l])){
                if(st.count(s[r])){
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                else r--;
            }
            else l++;
        }
        return s;
    }
};