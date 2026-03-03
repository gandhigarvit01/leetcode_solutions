class Solution {
public:
    char findKthBit(int n, int k) {
        string prev = "0";
        string curr = "";
        for(int i=2; i<=n; i++){
            int m = prev.size();
            string rev_inv = "";
            for(int j=m-1; j>=0; j--){
                if(prev[j]=='0') rev_inv.push_back('1');
                else rev_inv.push_back('0');
            }
            curr = prev + '1' + rev_inv;
            prev = curr; 
        }
        return prev[k-1];
    }
};