class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        int val = -1;
        for(int i=1; i<n-1; i++){
            if(num[i-1]==num[i] && num[i+1]==num[i]){
                val = max(val,num[i]-'0');
            }
        }
        if(val==-1){
            return ans;
        }
        ans = to_string(val);
        ans += ans + ans;
        return ans;
    }
};