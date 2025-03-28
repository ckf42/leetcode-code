struct Solution {
    bool checkItv(vector<pair<int, int>> &itvList){
        int currTail = 0, count = 0;
        for (auto [a, b] : itvList){
            if (currTail <= a){
                ++count;
            }
            currTail = max(currTail, b);
        }
        return count >= 3;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int k = rectangles.size();
        vector<pair<int, int>> itvList(k);
        for (int i = 0; i < k; ++i){
            itvList[i] = make_pair(rectangles[i][0], rectangles[i][2]);
        }
        ranges::sort(itvList);
        if (this->checkItv(itvList)){
            return true;
        }
        for (int i = 0; i < k; ++i){
            itvList[i] = make_pair(rectangles[i][1], rectangles[i][3]);
        }
        ranges::sort(itvList);
        return this->checkItv(itvList);
    }
};
