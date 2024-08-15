struct Solution {
    int getParent(int i, vector<int> &parents){
        int temp;
        while (parents[i] != i){
            temp = parents[i];
            parents[i] = parents[parents[i]];
            i = temp;
        }
        return i;
    }

    void makeUnion(int i, int j, vector<int> &parents, vector<int> &sizes){
        i = this->getParent(i, parents);
        j = this->getParent(j, parents);
        if (i == j){
            return;
        }
        if (sizes[i] < sizes[j]){
            swap(i, j);
        }
        parents[j] = i;
        sizes[i] += sizes[j];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parents(n, 0), sizes(n, 1);
        for (int i = 0; i < n; ++i){
            parents[i] = i;
        }
        for (auto &e : edges){
            this->makeUnion(e[0], e[1], parents, sizes);
        }
        return this->getParent(source, parents) == this->getParent(destination, parents);
    }
};
