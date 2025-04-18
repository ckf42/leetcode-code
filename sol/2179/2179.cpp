struct Solution {
    using ll = long long;
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> loc2(n, 0), fTree(n + 1, 0);
        for (int i = 0; i < n; ++i){
            loc2[nums2[i]] = i;
        }
        ll res = 0;
        for (int j = 0; j < n; ++j){
            int j2 = loc2[nums1[j]];
            ll xCount = 0;
            int idx = j2 + 1;
            while (idx > 0){
                xCount += fTree[idx];
                idx -= (idx & -idx);
            }
            idx = j2 + 1;
            while (idx <= n){
                ++fTree[idx];
                idx += (idx & -idx);
            }
            res += xCount * (xCount + n - 1 - j2 - j);
        }
        return res;
    }
};
