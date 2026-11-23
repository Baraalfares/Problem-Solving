class ProductOfNumbers {
public:
    vector<int>vec;
    ProductOfNumbers() {
        vec = {1};
    }
    
    void add(int num) {
        if(num == 0)
            vec = {1};
        else {
        int prod = num * vec.back();
        vec.push_back(prod);
        }
    }
    
    int getProduct(int k) {
        int n = vec.size() - 1;
        if(k >= vec.size())
            return 0;
        return vec[n] / vec[n - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */