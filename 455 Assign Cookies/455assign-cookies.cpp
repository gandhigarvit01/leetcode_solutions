class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0,c=0;
        int m=g.size();
        int n=s.size();
        while(l<m && r<n){
            if(s[r]>=g[l]){
                c++;
                l++;
            }
            r++;
        }
        return c;

    }
};