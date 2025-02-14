struct Solution {
    string removeOccurrences(string &s, string &part) {
        string res;
        char last = part.back();
        for (char c : s){
            res.push_back(c);
            if (c == last 
                    && res.size() >= part.size() 
                    && res.ends_with(part)){
                res.erase(res.size() - part.size(), part.size());
            }
        }
        return res;
    }
};
