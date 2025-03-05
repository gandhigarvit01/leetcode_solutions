class Solution {
public:
    long long coloredCells(int n) {
        int k=1;
        long long sum = 1;
        while(k<n){
            sum += 4*k;
            k++;
        }
        return sum;
    }
};