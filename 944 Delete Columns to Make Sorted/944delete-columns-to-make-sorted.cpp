class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int k = strs[0].size();
        int deletions = 0;
        vector<int> deleted(k,0);
        vector<char> chars(k,0);
        for(string s : strs){
            for(int i=0; i<k; i++){
                if(s[i]>=chars[i]){
                    chars[i] = s[i];
                }
                else{
                    if(deleted[i]==0){
                        deleted[i] = 1;
                        deletions++;
                    }
                    chars[i] = s[i];
                }
            }
        }
        return deletions;
    }
};