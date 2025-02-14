struct ProductOfNumbers {
    vector<int> m_seq;
    ProductOfNumbers(): m_seq(1, 1) {}
    
    void add(int num) {
        if (num == 0){
            m_seq.clear();
            m_seq.push_back(1);
        } else {
            m_seq.push_back(m_seq.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = m_seq.size();
        if (k >= n){
            return 0;
        }
        return m_seq.back() / m_seq[n - k - 1];
    }
};

