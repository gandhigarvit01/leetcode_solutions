class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int pieces = 1;
        for(int i=0; i<n; i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]++;
            }
            else{
                pieces++;
                mpp.clear();
                mpp[s[i]]++;
            }
        }
        return pieces;
    }
};