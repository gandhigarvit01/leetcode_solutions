class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int k=0,j=0;
        int a=0,b=0;
        for(int i=0; i<n; i++){
            k= nums1[i]^k;
        }
        for(int i=0; i<m; i++){
            j=nums2[i]^j;
        }
        for(int i=0; i<n; i++){
            a=a^j;
        }
        for(int i=0; i<m; i++){
            b=b^k;
        }

       return a^b;
        }
};