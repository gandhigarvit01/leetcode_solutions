class Solution {
public:
    int minSensors(int n, int m, int k) {
    int cover = 2*k+1;
    int rows = (n%cover==0)?n/cover:n/cover+1;  
    int cols = (m%cover==0)?m/cover:m/cover+1;  
    return rows*cols;
    }
};