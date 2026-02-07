class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int after_a = 0, before_b = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                after_a++;
            }
        }
        int ans = INT_MAX;
        int deletions = after_a;
        for(int i=0; i<n; i++){
            ans = min(ans,after_a + before_b);
            if(s[i]=='a'){
                after_a--;
            }
            else{
                before_b++;
            }
        }
        ans = min(ans, after_a + before_b);
        return ans;
    }
};