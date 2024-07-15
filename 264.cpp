struct Solution {
    static vector<int> rec;
    static int idx[3];

    int nthUglyNumber(int n) {
        while (n >= this->rec.size())    {
            int l1 = this->rec[this->idx[0]] * 2,
                l2 = this->rec[this->idx[1]] * 3,
                l3 = this->rec[this->idx[2]] * 5;
            int x = min(l1, min(l2, l3));
            if (x == l1){
                ++this->idx[0];
            } else if (x == l2){
                ++this->idx[1];
            } else {
                ++this->idx[2];
            }
            if (x != this->rec.back()){
                this->rec.push_back(x);
            }
        }
        return this->rec[n - 1];
    }
};

vector<int> Solution::rec = {1};
int Solution::idx[3] = {0, 0, 0};
