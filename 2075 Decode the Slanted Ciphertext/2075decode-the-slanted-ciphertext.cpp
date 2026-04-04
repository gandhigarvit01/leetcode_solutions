class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n/rows;
        string ans = "";
        for(int col=0; col<cols; col++){
            for(int row=0; row<rows; row++){
                int idx = row*cols + (col + row);
                if(idx<n) ans.push_back(encodedText[idx]);
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};