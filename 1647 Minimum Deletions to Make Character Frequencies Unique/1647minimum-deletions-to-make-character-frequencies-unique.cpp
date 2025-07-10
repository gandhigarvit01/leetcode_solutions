class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        int freq[26] = {0};
        for(char &ch : s){
            freq[ch-'a']++;
        }
        int ans = 0;
        unordered_set<int> st;

        for(int i=0; i<26; i++){
            while(freq[i]>0 && st.find(freq[i])!=st.end()){
                freq[i] -= 1;
                ans++;
            }
            st.insert(freq[i]);
        }
        return ans;
    }
};