class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string c = to_string(num);
        int j = -1, k=-1, l=-1;
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i]!='9'){
                j = a[i];
                break;
            }
        }
        if(j!=-1){
            for(int i=0; i<n; i++){
                if(a[i]==j){
                    a[i]='9';
                }
            }
        }
        for(int i=0; i<n; i++){
            if(c[i]!='1' && c[i]!='0'){
                k = c[i];
                l = i;
                break;
            }
        }
        if(k!=-1 && l!=0){
            for(int i=0; i<n; i++){
                if(c[i]==k){
                    c[i]='0';
                }
            }
        }
        else if(k!=-1 && l==0){
            for(int i=0; i<n; i++){
                if(c[i]==k){
                    c[i]='1';
                }
            }
        }

        return stoi(a)-stoi(c);
        
    }
};