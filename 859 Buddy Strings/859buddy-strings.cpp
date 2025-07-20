class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(m!=n){
            return false;
        }
        int swaps = 0;
        char s1=0,s2=0,goal1=0,goal2=0;
        for(int i=0; i<n; i++){
            if(swaps==0 && s[i]!=goal[i]){
                s1 = s[i];
                goal1 = goal[i];
                swaps++;    
            }
            else if(swaps==1 && s[i]!=goal[i]){
                s2 = s[i];
                goal2 = goal[i];
                swaps++;
            }
            else if(s[i]!=goal[i]){
                swaps++;
            }
        }
        if(swaps==2){
            if(s1==goal2 && s2==goal1){
                return true;
            }
        }
        else if(swaps==0){
            vector<int> vec(26,0);
            for(int i=0; i<n; i++){
                vec[s[i]-'a']++;
            }
            for(int i=0; i<26; i++){
                if(vec[i]>=2){
                    return true;
                }
            }
        }
        return false;
    }
};