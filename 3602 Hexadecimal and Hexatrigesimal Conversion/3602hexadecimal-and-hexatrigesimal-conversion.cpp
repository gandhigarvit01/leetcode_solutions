class Solution {
public:
    string toBase(int num, int base) {
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";

        if (num == 0) return "0";

        while (num > 0) {
            res = chars[num % base] + res;
            num /= base;
        }

        return res;
    }

    string concatHex36(int n) {
        int sq = n * n;
        int cube = n * n * n;

        string hex = toBase(sq, 16);   // Base 16 (Hexadecimal)
        string base36 = toBase(cube, 36); // Base 36 (Hexatrigesimal)

        return hex + base36;
    }
};
