struct Solution {
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string tag = "";
        for (string w : words){
            string tagw = w;
            ranges::sort(tagw);
            if (tagw != tag){
                res.push_back(w);
                tag = tagw;
            }
        }
        return res;
    }
};
