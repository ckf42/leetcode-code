struct Solution {
    int dfs(int idx, vector<Employee*> &employees, int (&h)[2001]){
        int res = employees[idx]->importance;
        for (int s : employees[idx]->subordinates){
            res += this->dfs(h[s], employees, h);
        }
        return res;
    }
    inline int getImportance(vector<Employee*> employees, int id) {
        int h[2001] = {0};
        for (int i = 0; i < employees.size(); ++i){
            h[employees[i]->id] = i;
        }
        return this->dfs(h[id], employees, h);
    }
};
