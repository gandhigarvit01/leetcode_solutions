class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n==1) return 0;
        if(n==2){
            if(s[0]>s[1]) return -1;
            return 0;
        }
        int asc = 0;
        for(int i=1; i<n; i++){
            if(s[i]>=s[i-1]) asc++;
        }
        if(asc == n-1) return 0;
        int mini = INT_MAX, maxi = INT_MIN;
        int minis = 0, maxis = 0;
        for(int i=0; i<n; i++){
            if(s[i]<mini){
                mini = s[i];
                minis = 1;
            }
            else if(s[i]==mini){
                minis++;
            }
            if(s[i]>maxi){
                maxi = s[i];
                maxis = 1;
            }
            else if(s[i]==maxi){
                maxis++;
            }
        }
        if(s[0]==maxi && s[n-1]==mini){
            if(maxis==1 && minis==1) return 3;
            else return 2;
        }
        if(s[0]==mini || s[n-1]==maxi){
            return 1;
        }
        return 2;
    }
};