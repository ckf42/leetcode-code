#include <algorithm>

struct Solution {
    bool dfs(int start, const vector<int>& leftChild, const vector<int>& rightChild, vector<bool> &visited){
        if (visited[start]){
            return false;
        }
        visited[start] = true;
        if (leftChild[start] != -1){
            if (!dfs(leftChild[start], leftChild, rightChild, visited)){
                return false;
            }
        }
        if (rightChild[start] != -1){
            if (!dfs(rightChild[start], leftChild, rightChild, visited)){
                return false;
            }
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, const vector<int>& leftChild, const vector<int>& rightChild) {
        vector<int> inCounter(n, 0);
        for (int i = 0; i < n; ++i){
            if (leftChild[i] != -1){
                if (i == leftChild[i]){
                    return false;
                }
                ++inCounter[leftChild[i]];
            }
            if (rightChild[i] != -1){
                if (i == rightChild[i]){
                    return false;
                }
                ++inCounter[rightChild[i]];
            }
        }
        int idx = 0;
        while (idx < n && inCounter[idx] != 0){
            ++idx;
        }
        if (idx == n){
            return false;
        }
        for (int i = idx + 1; i < n; ++i){
            if (inCounter[i] == 0){
                return false;
            }
        }
        for (const int &d : inCounter){
            if (d >= 2){
                return false;
            }
        }
        vector<bool> visited(n, false);
        bool res = dfs(idx, leftChild, rightChild, visited);
        if (!res){
            return false;
        }
        return find(visited.cbegin(), visited.cend(), false) == visited.cend();
    }
};
