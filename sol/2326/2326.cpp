struct Solution {
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int i = 0, j = 0, diffi = 0, diffj = 1;
        while (head != nullptr){
            res[i][j] = head->val;
            head = head->next;
            int newi = i + diffi, newj = j + diffj;
            if (!(0 <= newi && newi < m && 0 <= newj && newj < n && res[newi][newj] == -1)){
                newi = diffi;
                diffi = diffj;
                diffj = -newi;
                i += diffi;
                j += diffj;
            } else {
                i = newi;
                j = newj;
            }
        }
        return res;
    }
};
