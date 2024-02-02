struct Solution {
    static const string dseq;

    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int ll = to_string(low).size(), hl = to_string(high).size(), val;
        for (int l = ll; l <= hl; ++l){
            for (int s = 0; s < 10 - l; ++s){
                val = stoi(this->dseq.substr(s, l));
                if (low <= val && val <= high){
                    res.push_back(val);
                }
            }
        }
        return res;
    }
};
const string Solution::dseq = "123456789";
