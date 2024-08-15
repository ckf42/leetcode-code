#include <unordered_map>

struct Solution {
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int n = matrix.size(), m = matrix[0].size();
       for (int j = 1; j < m; ++j) {
           matrix[0][j] += matrix[0][j - 1];
       }
       for (int i = 1; i < n; ++i){
           matrix[i][0] += matrix[i - 1][0];
           for (int j = 1; j < m; ++j){
               matrix[i][j] += matrix[i][j - 1] - matrix[i - 1][j - 1] + matrix[i - 1][j];
           }
       }
       int count = 0, sub;
       unordered_map<int, int> rec;
       for (int r1 = 0; r1 < n; ++r1){
           for (int r2 = r1; r2 < n; ++r2){
               rec.clear();
               rec.insert({0, 1});
               for (int c = 0; c < m; ++c){
                   sub = matrix[r2][c] - (r1 > 0 ? matrix[r1 - 1][c] : 0);
                   count += rec[sub - target];
                   ++rec[sub];
               }
           }
       }
       return count;
    }
};
