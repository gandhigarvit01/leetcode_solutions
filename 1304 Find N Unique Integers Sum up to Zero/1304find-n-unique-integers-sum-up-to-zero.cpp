class Solution {
public:
    vector<int> sumZero(int n) {
        int m = n/2;
        int k = -1*m;
        int i = m;
        vector<int> result;
        while(i>=k){
            if(i==0 && n%2!=0){
                result.push_back(i);
            }
            else if(i!=0){
                result.push_back(i);
            }
            i--;
        }
        return result;
    }
};