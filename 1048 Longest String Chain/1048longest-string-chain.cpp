class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();});
        int n = words.size();
        vector<int> vec(n,1);
        int lc = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(words[j].size() == words[i].size()-1){
                    int l = words[j].size();
                    int k = 0;
                    int p=0,q=0;
                    while(p<words[j].size() && q<words[i].size()){
                        if(words[j][p]==words[i][q]){
                            p++;
                            q++;
                        }
                        else{
                            q++;
                            k++;
                        }
                    }
                    k += words[i].size()-q;
                    if(k==1){
                        vec[i] = max(vec[i],vec[j]+1);
                        lc = max(lc,vec[i]);
                    }
                }
            }
        }
        return lc;
    }
};