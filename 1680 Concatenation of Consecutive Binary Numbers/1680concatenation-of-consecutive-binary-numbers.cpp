class Solution {
public:
    int concatenatedBinary(int n) {
        string s;
        long long ans = 0;
        int mod = 1e9+7;
        for(int i=1; i<=n; i++){
            string binary = bitset<32>(i).to_string();
            binary.erase(0, binary.find_first_not_of('0'));
            int m = binary.size();
            for(int i=0; i<m; i++){
                ans = (ans*2 + (binary[i]-'0'))%mod;
            }
        }
        return ans;
    }
};