class Solution {
public:
    vector<int> segtree;
    void update(int i, int l, int r, int idx){
        if(l==r){
            segtree[i] = 1;
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx);
        }
        else{
            update(2*i+2,mid+1,r,idx);
        }
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
    int find_in_range(int i, int l, int r, int start, int end){
        if(l>end || r<start || l>r) return 0;
        if(l>=start && r<=end) return segtree[i];
        int mid = (l+r)/2;
        return find_in_range(2*i+1,l,mid,start,end) + find_in_range(2*i+2,mid+1,r,start,end);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        segtree.resize(4*n,0);
        long long ans = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums2[i]] = i;
        }
        update(0,0,n-1,mpp[nums1[0]]);
        for(int i=1; i<n; i++){
            int idx = mpp[nums1[i]];
            int left1 = i;
            int left2 = find_in_range(0,0,n-1,0,idx-1);
            int uncommon = left1 - left2;
            int common_in_left = left2;
            int common_in_right = n-1-idx-uncommon;
            ans += (1LL*(common_in_left))*(common_in_right);
            update(0,0,n-1,idx);
        }
        return ans;
    }
};