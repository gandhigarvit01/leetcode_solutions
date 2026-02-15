class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i=n-1, j=m-1;
        int carry = 0;
        string ans = "";
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            ans = to_string(sum % 2) + ans;
            carry = sum/2;
        }
        return ans;
    }
};