class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        int left = 0, i = 0;
        int right = 0, j = 0;
        while(left<n && right<m){
            if(word1[left][i]!=word2[right][j]){
                return false;
            }
            i++;
            j++;
            if(i==word1[left].size()){
                i=0;
                left++;
            }
            if(j==word2[right].size()){
                j=0;
                right++;
            }
        } 
        if(left==n && right==m){
            return true;
        }
        return false;
    }
};