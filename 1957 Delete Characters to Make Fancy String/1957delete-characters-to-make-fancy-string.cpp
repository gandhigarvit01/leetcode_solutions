class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int n = s.size();
        char prev = 0;
        int i=0;
        while(i<n){
            if(result.empty()){
                result.push_back(s[i]);
            }
            else if(prev==result.back() && prev==s[i]){
            }
            else{
                prev = result.back();
                result.push_back(s[i]);
            }
            i++;
        }
        return result;
    }
};