class ProductOfNumbers {
public:
vector<int>PreFixProduct;
    ProductOfNumbers() 
    {
        PreFixProduct={1};
    }
    void add(int num) 
    {
        if(num == 0)
        {
             PreFixProduct={1};
        }
        else
        {
            PreFixProduct.push_back(PreFixProduct.back()* num);
        }
    }
    
    int getProduct(int k) 
    {
        int PreFixProductSize = PreFixProduct.size();
        if(PreFixProductSize <=k)
        {
            return 0;
        }
        else
        {
            int divider = PreFixProduct[PreFixProductSize - k -1];
            int result = PreFixProduct.back() / divider;
            return result;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */