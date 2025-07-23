class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int points = 0;
        string result1 = "";
        string result2 = "";
        int i=0;
        if(y>x){
            while(i<n){
                if(!result1.empty() && result1.back()=='b' && s[i]=='a'){
                    points += y;
                    result1.pop_back();
                }
                else{
                    result1.push_back(s[i]);
                }
                i++;
            }
            i=0;
            while(i<result1.size()){
                if(!result2.empty() && result2.back()=='a' && result1[i]=='b'){
                    points += x;
                    result2.pop_back();
                }
                else{
                    result2.push_back(result1[i]);
                }
                i++;
            }
        }
        else{
            while(i<n){
                if(!result1.empty() && result1.back()=='a' && s[i]=='b'){
                    points += x;
                    result1.pop_back();
                }
                else{
                    result1.push_back(s[i]);
                }
                i++;
            }
            i=0;
            while(i<result1.size()){
                if(!result2.empty() && result2.back()=='b' && result1[i]=='a'){
                    points += y;
                    result2.pop_back();
                }
                else{
                    result2.push_back(result1[i]);
                }
                i++;
            }
        }
        return points;
    }
};