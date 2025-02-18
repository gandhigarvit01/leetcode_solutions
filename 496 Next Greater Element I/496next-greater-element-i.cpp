class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        stack<int> st;
        int n=nums2.size();
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(nums2[i]);
                mpp[nums2[i]]=-1;
            }
            else if(st.top()<nums2[i]){
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(nums2[i]);
                    mpp[nums2[i]]=-1;
                }
                else{
                    mpp[nums2[i]]=st.top();
                    st.push(nums2[i]);  
                }
            }
            else{
                mpp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        int m=nums1.size();
        for(int i=0; i<m; i++){
            nums1[i]=mpp[nums1[i]];
        }
        return nums1;
    }
};