class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        int n = words.size();
        for(int i=0; i<n; i++){
            mpp[words[i]]++;
        }
        int count = 0;
        int l = 0;
        for(auto it : mpp){
            string s = it.first;
            if(s[0]==s[1]){
                if(it.second%2!=0 && l==0){
                    l = 1;
                    count += 2;
                    it.second--;
                }
                if(it.second%2!=0){
                    it.second = it.second-1;
                }
                count += 2*it.second;
            }
            else{
                string rev = s;
                swap(rev[0],rev[1]);

                if(mpp.find(rev)!=mpp.end()){
                    int k = min(it.second,mpp[rev]);
                    count += 4*k;

                    mpp[rev] = 0;
                    mpp[s] = 0;
                }
            }
        }
        return count;
    }
};