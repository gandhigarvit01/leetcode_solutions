class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto vec : knowledge){
            mpp[vec[0]] = vec[1];
        }
        string k;
        int n = s.size();
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                string t;
                i++;
                while(s[i]!=')'){
                    t.push_back(s[i]);
                    i++;
                }
                i++;
                if(mpp.find(t)!=mpp.end()){
                    k += mpp[t];
                }
                else k.push_back('?');
            }
            else{
                k.push_back(s[i]);
                i++;
            }
        }
        return k;
    }
};