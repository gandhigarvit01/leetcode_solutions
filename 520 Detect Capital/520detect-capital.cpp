class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cap_count = 0;
        for(int i=0; i<n; i++){
            if(word[i]<='Z'){
                cap_count++;
            }
        }
        if(cap_count==n || cap_count==0 || (cap_count==1 && word[0]<='Z')) return true;
        return false;
    }
};