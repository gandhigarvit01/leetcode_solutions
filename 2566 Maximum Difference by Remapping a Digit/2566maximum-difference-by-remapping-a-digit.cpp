class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = to_string(num);
        int k=0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]!='9'){
                k = s[i];
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i]==k){
                s[i]='9';
            }
        }
        k = t[0];
        for(int i=0; i<n; i++){
            if(t[i]==k){
                t[i]='0';
            }
        }
        return stoi(s)-stoi(t);
    }
};