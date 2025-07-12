class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int mycoins = 0;
        sort(piles.begin(),piles.end());
        int i=n/3;
        while(i<n){
            mycoins += piles[i];
            i += 2;
        }
        return mycoins;
    }
};