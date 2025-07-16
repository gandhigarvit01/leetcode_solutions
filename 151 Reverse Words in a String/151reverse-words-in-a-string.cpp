class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string k,t;
        int i=0; 
        while(i<n){
            if(s[i]==' '){
                if(t.size()!=0){
                    int l = 0;
                    int r = t.size()-1;
                    while(l<r){
                        swap(t[l],t[r]);
                        l++;
                        r--;
                    }
                    k += t;
                    t.clear();
                    k += ' ';
                }
            }
            else{
                t += s[i];
            }
            i++;
        }
        int left = 0;
        int right = k.size()-1;
        if(t.size()!=0){
            int a = 0;
            int b = t.size()-1;
            while(a<b){
                swap(t[a],t[b]);
                a++;
                b--;
            }
            k += t;
        }
        else{
            k.erase(right,1);
        }
        right = k.size()-1;
        while(left<right){
            swap(k[left],k[right]);
            left++;
            right--;
        }
        return k;
    }
};