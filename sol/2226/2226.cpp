struct Solution {
    using ll = long long;
    inline bool isFeasible(int m, vector<int> &candies, ll k){
        ll count = 0;
        for (int x : candies){
            count += x / m;
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll total = 0;
        int maxi = -1;
        for (int x : candies){
            total += x;
            maxi = max(maxi, x);
        }
        if (total < k){
            return 0;
        }
        if (total == k){
            return 1;
        }
        int s = 1, e = maxi + 1;
        while (s < e){
            int m = (s + e) / 2;
            if (this->isFeasible(m, candies, k)){
                s = m + 1;
            } else {
                e = m;
            }
        }
        return e - 1;
    }
};
