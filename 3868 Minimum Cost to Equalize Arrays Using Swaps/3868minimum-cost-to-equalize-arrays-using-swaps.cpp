class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int xtra1 = 0, xtra2 = 0;
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums1[i]);
            st.insert(nums2[i]);
            mpp1[nums1[i]]++;
            mpp2[nums2[i]]++;
        }
        for(auto it = st.begin(); it!=st.end(); it++){
            int val = *it;
            int val1 = mpp1[val];
            int val2 = mpp2[val];
            if((val1+val2)%2!=0) return -1;
            else{
                if(val1>val2){
                    xtra1 += val1-val2;
                }
                else if(val1<val2){
                    xtra2 += val2-val1;
                }
            }
        }
        if(xtra1!=xtra2) return -1;
        return xtra1/2;
    }
};