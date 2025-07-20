class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(m!=n){
            return false;
        }
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for(int i=0; i<n; i++){
            vec1[word1[i]-'a']++;
            vec2[word2[i]-'a']++;
        }
        // for checking availability of same chars 
        for(int i=0; i<26; i++){
            if((vec1[i]==0 && vec2[i]!=0) || (vec1[i]!=0 && vec2[i]==0)){
                return false;
            }
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        // for checking frequency of chars
        return vec1==vec2;
    }
};