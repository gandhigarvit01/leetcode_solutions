class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n==0){
            return 0;
        }
        if(n==1 && tokens[0]<=power){
            return 1;
        }
        sort(tokens.begin(),tokens.end());
        int l = 0;
        int r = n-1;
        int score = 0;
        int maxi = 0;
        while(l<=r){
            if(power>=tokens[l]){
                score++;
                maxi = max(maxi,score);
                power -= tokens[l];
                l++;
            }
            else if(score>0){
                score--;
                maxi = max(maxi,score);
                power += tokens[r];
                r--;
            }
            else{
                break;
            }
        }
        return maxi;
    }
};