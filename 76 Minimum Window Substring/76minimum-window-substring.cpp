class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int req = m;
        int ans = INT_MAX;
        int idx;
        if(m>n) return "";
        vector<int> vec(58,0);
        for(int i=0; i<m; i++){
            vec[t[i]-'A']++;
        }
        int l=0, r=0;
        while(r<n){
            if(vec[s[r]-'A']>0){
                req--;
            }
            vec[s[r]-'A']--;
            while(req==0){
                if(r-l+1 < ans){
                    ans = r-l+1;
                    idx = l;
                }
                vec[s[l]-'A']++;
                if(vec[s[l]-'A']>0){
                    req++;
                }
                l++;
            }
            r++;
        }
        if(ans==INT_MAX) return "";
        return s.substr(idx,ans);
    }
};