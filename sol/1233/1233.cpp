struct Solution {
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        ranges::sort(folder);
        string buff;
        for (string &p : folder){
            if (res.empty() || !p.starts_with(buff)){
                res.push_back(p);
                buff = p + '/';
            }
        }
        return res;
    }
};
