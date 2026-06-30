class NumArray {
public:
    vector<int> segtree;
    int n;

    void fill(int i, int l, int r, vector<int>& nums){
        if(l==r){
            segtree[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        fill(2*i+1, l, mid, nums);
        fill(2*i+2, mid+1, r, nums);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n);
        fill(0,0,n-1,nums);
    }
    
    void updte(int i, int l, int r, int idx, int val){
        if(l==r){
            segtree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            updte(2*i+1, l, mid, idx, val);
        }
        else{
            updte(2*i+2, mid+1, r, idx, val);
        }
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    void update(int index, int val) {
        updte(0,0,n-1,index,val);
    }

    int sum(int i, int l, int r, int low, int high){
        if(r<low || l>high) return 0;
        if(l>=low && r<=high) return segtree[i];
        int mid = l + (r-l)/2;
        int left = sum(2*i+1, l, mid, low, high);
        int right = sum(2*i+2, mid+1, r, low, high);
        return left + right;
    }
    
    int sumRange(int left, int right) {
        return sum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */