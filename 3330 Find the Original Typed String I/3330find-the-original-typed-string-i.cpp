class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int k = 1;
        int i=0;
        int j=1;
        while(j<word.size()){
            if(word[i]==word[j]){
                j++;
            }
            else if(word[i]!=word[j]){
                k += j-i-1;
                i = j;
                j++;
            }
        }
        k += j-i-1;
        return k;
    }
};