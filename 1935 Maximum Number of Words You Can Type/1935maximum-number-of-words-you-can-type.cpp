class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mpp;
        for(int i=0; i<brokenLetters.size(); i++){
            mpp[brokenLetters[i]]++;
        }
        int ans = 0;
        int n = text.size();
        int cantype = 0;
        for(int i=0; i<n; i++){
            if(text[i]==' '){
                if(cantype==0){
                    ans++;
                }
                cantype = 0;
            }
            else{
                if(mpp.find(text[i])!=mpp.end()){
                    cantype++;
                }
            }
        }
        if(cantype==0){
            ans++;
        }
        return ans;
    }
};