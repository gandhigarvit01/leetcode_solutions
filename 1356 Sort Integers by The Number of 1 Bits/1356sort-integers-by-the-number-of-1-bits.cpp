class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [](int& a, int& b){
            int setbits_a = __builtin_popcount(a);
            int setbits_b = __builtin_popcount(b);
            if(setbits_a==setbits_b) return a<b;
            return setbits_a < setbits_b;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};