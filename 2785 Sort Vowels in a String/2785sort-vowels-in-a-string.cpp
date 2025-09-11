class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string t(n, '\0');
        unordered_map<char,int> mpp;
        unordered_map<int,char> mp;
        mpp['A'] = 0, mp[0] = 'A', mpp['E'] = 1, mp[1] = 'E', mpp['I'] = 2, mp[2] = 'I';
        mpp['O'] = 3, mp[3] = 'O', mpp['U'] = 4, mp[4] = 'U', mpp['a'] = 5, mp[5] = 'a';
        mpp['e'] = 6, mp[6] = 'e', mpp['i'] = 7, mp[7] = 'i';
        mpp['o'] = 8, mp[8] = 'o', mpp['u'] = 9, mp[9] = 'u';
        vector<int> vowel(10,0);
        for(int i=0; i<n; i++){
            if(mpp.find(s[i])!=mpp.end()){
                //vowel
                vowel[mpp[s[i]]]++;
            }
            else{
                //consonant
                t[i] = s[i];
            }
        }
        int i=0, j=0;
        while(i<n){
            while(j<10 && vowel[j]==0){
                j++;
            }
            if(t[i]=='\0'){
                t[i] = mp[j];
                vowel[j]--;
            }
            else{
                i++;
            }
        }
        return t;
    }
};