class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, maxi = -1;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }
        maxi = sum;
        int r = n-1;
        int l = k-1;
        while(l>=0){
            sum = sum + cardPoints[r] - cardPoints[l];
            l--;
            r--;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};