class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();
        int ans = 0;
        vector<int> small(26,0);
        vector<int> big(26,0);
        vector<int> dig(10,0);
        int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0;
        for(int i=0; i<n; i++){
            if(islower(password[i])){
                small[password[i]-'a']++;
            }
            else if(isupper(password[i])){
                big[password[i]-'A']++;
            }
            else if(isdigit(password[i])){
                dig[password[i]-'0']++;
            }
            else{
                if(password[i]=='!') sc1++;
                if(password[i]=='@') sc2++;
                if(password[i]=='#') sc3++;
                if(password[i]=='$') sc4++;
            }
        }
        for(int i=0; i<26; i++){
            if(small[i]>0) ans+=1;
            if(big[i]>0) ans+=2;
            if(i<=9 && dig[i]>0) ans+=3;
        }
        if(sc1>0) ans+=5;
        if(sc2>0) ans+=5;
        if(sc3>0) ans+=5;
        if(sc4>0) ans+=5;
        return ans;
    }
};