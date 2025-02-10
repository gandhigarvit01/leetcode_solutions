class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        int c=0;
        for(int i=n-1; i>=0; i--){
            if(isdigit(s[i])){
                c++;
                s.erase(i,1);
            }
            else{
                if(c>0){
                    c--;
                    s.erase(i,1);
                }
            }

        }
        return s;
    }
};