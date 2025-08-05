class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int place = 0;
        vector<bool> placed(n,false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(baskets[j]>=fruits[i] && placed[j]==false){
                    placed[j] = true;
                    place++;
                    break;
                }
            }
        }
        return n-place;
    }
};