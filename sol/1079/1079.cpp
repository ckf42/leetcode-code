struct Solution {
    int count(vector<int> &counter){
        int res = 1;
        for (auto it = counter.begin(); it != counter.end(); ++it){
            if (*it == 0){
                continue;
            }
            --*it;
            res += this->count(counter);
            ++*it;
        }
        return res;
    }

    int numTilePossibilities(string &tiles) {
        int n = tiles.size();
        int freq[26] = {0};
        for (char c : tiles){
            ++freq[c - 'A'];
        }
        vector<int> counter;
        for (int i = 0; i < 26; ++i){
            if (freq[i] != 0){
                counter.push_back(freq[i]);
            }
        }
        return this->count(counter) - 1;
    }
};
