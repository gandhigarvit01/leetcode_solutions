class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n,-1);
        for(int i=0; i<n; i++){
            dp[i] = i+1;
        }
        unordered_map<string,int> mpp;
        for(int i=0; i<dictionary.size(); i++){
            mpp[dictionary[i]]++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(mpp.find(s.substr(j,i-j+1))!=mpp.end()){
                    dp[i] = min(dp[i],j>0?dp[j-1]:0);
                }
                else{
                    dp[i] = min(dp[i],i-j+1 + (j>0?dp[j-1]:0));
                }
            }
        }
        return dp[n-1];
    }
};