class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        int v=0,c=0;
        if(n<3){
            return false;
        }
        for(int i=0; i<n; i++){
            if(isalpha(word[i])){
                char k = tolower(word[i]);
                if(k=='a'||k=='e'||k=='i'||k=='o'||k=='u'){
                    v++;
                }
                else{
                    c++;
                }
            }
            else if(isdigit(word[i])){
            }
            else{
                return false;
            }
        }
        if(v>0 && c>0){
            return true;
        }
        return false;
    }
};