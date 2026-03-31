class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string vec(n+m-1,'*');
        vector<bool> fixed(n+m-1,false);
        // filling T values in word ----------------------
        for(int i=0; i<n; i++){
            if(str1[i]=='T'){
                for(int j=i; j<m+i; j++){
                    fixed[j] = true;
                    if(vec[j]!='*' && vec[j]!=str2[j-i]) return "";
                    else vec[j] = str2[j-i]; 
                }
            }
        }
        // filling empty values---------------------------
        for(int i=0; i<n+m-1; i++){
            if(vec[i]=='*') vec[i] = 'a';
        }
        // now checking and verifying all Fs--------------
        for(int i=0; i<n; i++){
            if(str1[i]=='F'){
                if(vec.substr(i,m)==str2){
                    // do some changes at non fixed position -
                    int j = i+m-1;
                    while(j>=i){
                        if(fixed[j]==true || vec[j]=='z') j--;
                        else{
                            vec[j]++;
                            break;
                        }
                    }
                    if(vec.substr(i,m)==str2) return "";
                }
            }
        }
        return vec;
    }
};