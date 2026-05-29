class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        for(int i=0; i<=25; i++){
            int l=0, r=0, key=k;
            while(r<n){
                if(s[r]-'A'==i) r++;
                else{
                    if(key<=0){
                        while(l<=r){
                            if(s[l]-'A'!=i){
                                key++;
                                l++;
                                break;
                            }
                            l++;
                        }
                    }
                    r++;
                    key--;
                }
                ans = max(ans, r-l);
            }
        }
        return ans;
    }
};