class ProductOfNumbers {
    vector<int> v;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int l=1;
        int i=v.size()-1;
        while(k>0){
            l *= v[i];
            i--;
            k--;
        }
        return l;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */