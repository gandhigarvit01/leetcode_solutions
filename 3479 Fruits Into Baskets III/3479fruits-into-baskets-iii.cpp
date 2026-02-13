class Solution {
public:
    vector<int> segmentree;
    void build(int i, int l, int r, vector<int>& baskets){
        if(l==r){
            segmentree[i] = baskets[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*i+1,l,mid,baskets);
        build(2*i+2,mid+1,r,baskets);
        segmentree[i] = max(segmentree[2*i+1],segmentree[2*i+2]);
    }
    int updated = 0;
    void update(int i, int l, int r, int threshold){
        if(l==r){
            if(segmentree[i]>=threshold){
                segmentree[i] = 0;
                updated = 1;
                return;
            }
            else return;
        }
        if(segmentree[i] < threshold) return;
        int mid = (l+r)/2;
        update(2*i+1,l,mid,threshold);
        if(updated==0){
            update(2*i+2,mid+1,r,threshold);
        }
        segmentree[i] = max(segmentree[2*i+1],segmentree[2*i+2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segmentree.resize(4*n);
        build(0,0,n-1,baskets);
        int placed = 0;
        for(int i=0; i<n; i++){
            if(fruits[i]<=segmentree[0]){
                placed++;
                updated = 0;
                update(0,0,n-1,fruits[i]);
            }
        }
        return n-placed;
    }
};