#include <unordered_map>

struct Solution {
    vector<string> uncommonFromSentences(string &s1, string &s2) {
        unordered_map<string, int> freq1, freq2;
        size_t ptr = 0, e = 0;
        while (true){
            e = s1.find(' ', ptr);
            ++freq1[s1.substr(ptr, e - ptr)];
            if (e == string::npos){
                break;
            }
            ptr = e + 1;
        }
        ptr = 0;
        while (true){
            e = s2.find(' ', ptr);
            ++freq2[s2.substr(ptr, e - ptr)];
            if (e == string::npos){
                break;
            }
            ptr = e + 1;
        }
        vector<string> res;
        for (auto &[k, v] : freq1){
            if (v == 1 && !freq2.contains(k)){
                res.push_back(k);
            }
        }
        for (auto &[k, v] : freq2){
            if (v == 1 && !freq1.contains(k)){
                res.push_back(k);
            }
        }
        return res;
    }
};
