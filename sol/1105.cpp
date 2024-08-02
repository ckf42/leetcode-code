struct Solution {
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> memo(n + 1, 1000001);
        memo[0] = 0;
        memo[1] = books[0][1];
        for (int i = 1; i < n; ++i){
            int w = 0, h = 0;
            for (int j = i; j >= 0; --j){
                w += books[j][0];
                h = max(h, books[j][1]);
                if (w > shelfWidth){
                    break;
                }
                memo[i + 1] = min(memo[i + 1], memo[j] + h);
            }
        }
        return memo[n];
    }
};
