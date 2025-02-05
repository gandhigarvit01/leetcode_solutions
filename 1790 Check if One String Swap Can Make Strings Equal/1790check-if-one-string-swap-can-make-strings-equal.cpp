class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        int k,l,p,q;
        int n=s1.size();
        if(s1==s2){
            return true;
        }
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                c++;
            if(c==1){
                k=s1[i];
                l=s2[i];
            }
            if(c==2){
                p=s1[i];
                q=s2[i];
            }
            }
            
        }
        if(c==2){
            if(k==q && l==p){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    
    }
};