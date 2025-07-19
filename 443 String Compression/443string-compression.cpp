class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n==1){
            return 1;
        }
        int insert = 0;
        int check = 1;
        int count = 1;
        char prev = chars[0];
        while(check<=n){
            if(check!=n && chars[check]==prev){
                count++;
            }
            else if(check==n || chars[check]!=prev){
                chars[insert++] = chars[check-1];
                if(count!=1){
                    string s = to_string(count);
                    for(int i=0; i<s.size(); i++){
                        chars[insert++] = s[i];
                    }
                }
                if(check!=n) prev = chars[check];
                count = 1;
            }
            check++;
        }
        return insert;
    }
};