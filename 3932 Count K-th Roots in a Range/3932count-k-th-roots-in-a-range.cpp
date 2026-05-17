class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int mini = ceil(pow(l, 1.0/k)-1e-9);
        int maxi = floor(pow(r, 1.0/k)+1e-9);
        return max(0,maxi-mini+1);
    }
};