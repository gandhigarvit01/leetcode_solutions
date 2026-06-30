class NumArray {
public:
    vector<int> seg;
    int n;
    void build(vector<int>& nums, int i, int l, int r){
        if(l==r){
            seg[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(nums, 2*i+1, l, mid);
        build(nums, 2*i+2, mid+1, r);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(nums,0,0,n-1);
    }

    int query(int i, int l, int r, int low, int high){
        if(l>high || r<low) return 0;
        if(l>=low && r<=high) return seg[i];
        int mid = l + (r-l)/2;
        int left = query(2*i+1, l, mid, low, high);
        int right = query(2*i+2, mid+1, r, low, high);
        return left + right;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */