class Solution {
public:
    string solve(string s){
        int n = s.size();
        int i=0, j=n-1;
        int breakpt = -1;
        int incr = 0;
        vector<string> vec;
        while(i<j){
            int balance = 0;
            breakpt = i;
            for(int k=i; k<=j; k++){
                if(s[k]=='1') balance++;
                else if(s[k]=='0') balance--;
                if(balance==0){
                    if(k==j && vec.size()==0){
                        continue;
                    }
                    string t = solve(s.substr(breakpt,k-breakpt+1));
                    vec.push_back(t);
                    breakpt = k+1;
                }
            }
            if(vec.size()==0){
                if(s[i+1]==s[i] && s[j-1]==s[j]){
                    i++, j--, incr++;
                }
                else{
                    return s;
                }
            }
            else break;
        }
        sort(vec.begin(),vec.end());
        int m = vec.size();
        string ans = "";
        for(int i=m-1; i>=0; i--){
            ans += vec[i];
        }
        for(int i=0; i<incr; i++){
            ans = '1' + ans + '0';
        }
        return ans;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};