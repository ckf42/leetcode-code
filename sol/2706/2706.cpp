struct Solution {
    int buyChoco(const vector<int>& prices, int money) {
        int minEle = 101, secMinEle = 101;
        for (const int &n : prices){
            if (n < minEle){
                secMinEle = minEle;
                minEle = n;
            } else if (n < secMinEle){
                secMinEle = n;
            }
        }
        minEle += secMinEle;
        return (minEle <= money) ? (money - minEle) : money;
    }
};
