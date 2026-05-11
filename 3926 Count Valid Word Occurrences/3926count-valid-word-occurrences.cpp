class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        int m = queries.size();
        string s;
        for(string t : chunks){
            s += t;
        }
        int l=0, r=0;
        int n = s.size();
        unordered_map<string,int> mpp;
        while(r<n && l<n){
            if(s[l]=='-' || s[l]==' ') l++;
            else{
                r = l;
                while(r<n){
                    if(s[r]=='-'){
                        if(r+1>=n) break;
                        if(s[r+1]=='-' || s[r+1]==' ') break;
                    }
                    if(s[r]==' ') break;
                    r++;
                }
                mpp[s.substr(l,r-l)]++;
                l = r+1;
            }
        }
        vector<int> ans(m,0);
        for(int i=0; i<m; i++){
            if(mpp.find(queries[i])!=mpp.end()){
                ans[i] = mpp[queries[i]];
            }
        }
        return ans;
    }
};