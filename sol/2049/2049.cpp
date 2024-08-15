struct Solution {
    int dfs(int x, long &maxScore, int &count, vector<int> &left, vector<int> &right){
        long prod = 1;
        int sub = 1, tmp;
        if (left[x] != -1){
            tmp = dfs(left[x], maxScore, count, left, right);
            sub += tmp;
            prod *= tmp;
        }
        if (right[x] != -1){
            tmp = dfs(right[x], maxScore, count, left, right);
            sub += tmp;
            prod *= tmp;
        }
        if (x != 0){
            prod *= left.size() - sub;
        }
        if (prod > maxScore){
            count = 1;
            maxScore = prod;
        } else if (prod == maxScore){
            ++count;
        }
        return sub;
    }
    inline int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> left(n, -1), right(n, -1);
        for (int i = 1; i < n; ++i){
            if (left[parents[i]] == -1){
                left[parents[i]] = i;
            } else {
                right[parents[i]] = i;
            }
        }
        long maxScore = 0;
        int count = 0;
        dfs(0, maxScore, count, left, right);
        return count;
    }
};
