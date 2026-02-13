class Solution {
public:
    int n;
    int char2case(char X, char Y, string& s){
        unordered_map<int,int> mpp;
        int result = 0;
        int x = 0, y = 0;
        mpp[0] = -1;
        for(int i=0; i<n; i++){
            if(s[i]==X || s[i]==Y){
                if(s[i]==X) x++;
                if(s[i]==Y) y++;
                if(mpp.find(x-y)!=mpp.end()){
                    result = max(result,i-mpp[x-y]);
                }
                else mpp[x-y] = i;
            }
            else{
                mpp.clear();
                mpp[0] = i;
                x = 0, y = 0;
            }    
        }
        return result;
    }
    int longestBalanced(string s) {
        n = s.size();
        int ans = 1;
        // single character case ----
        int curr = 1;
        for(int i=1; i<n; i++){     
            if(s[i]==s[i-1]){
                curr++;
                ans = max(ans,curr);
            }
            else{
                curr = 1;
            }
        }
        // double character case ----
        // (a,b)-
        ans = max(ans, char2case('a','b',s));
        // (a,c)-
        ans = max(ans, char2case('a','c',s));
        // (b,c)-
        ans = max(ans, char2case('b','c',s));
        // 3 char case (a,b,c) --
        int a=0, b=0, c=0;
        unordered_map<string,int> mp; // pair of (a-b) and (b-c);
        mp["0,0"] = -1;
        for(int i=0; i<n; i++){
            if(s[i]=='a') a++;
            if(s[i]=='b') b++;
            if(s[i]=='c') c++;
            string s = to_string(a-b) + ',' + to_string(b-c);
            if(mp.find(s)!=mp.end()){
                ans = max(ans, i-mp[s]);
            }
            else{
                mp[s] = i;
            }
        }
        return ans;
    }
};