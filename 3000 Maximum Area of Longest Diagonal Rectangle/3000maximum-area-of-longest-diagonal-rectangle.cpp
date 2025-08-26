class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long area = 0.0;
        long long diagonalsq = 0.0;
        for(int i=0; i<n; i++){
            long long length = dimensions[i][0];
            long long width = dimensions[i][1];
            long long currdiagsq = (length*length + width*width);
            if(currdiagsq>diagonalsq){
                diagonalsq = currdiagsq;
                area = length*width;
            }
            else if(diagonalsq==currdiagsq){
                area = max(area,length*width);
            }
        }
        return (int)area;
    }
};