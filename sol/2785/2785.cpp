struct Solution {   
    string sortVowels(string &s) {
        int counter[10] = {0};
        vector<int> indices;
        const string refStr = "AEIOUaeiou";
        for (int i = 0; i < s.size(); ++i){
            char c = s[i];
            if ((0x208222 >> (c & 31)) & 1){ // is vowel
                counter[refStr.find(c)] += 1;
                indices.push_back(i);
            }
        }
        int ptr = 0;
        for (int idx : indices){
            while (counter[ptr] == 0){
                ++ptr;
            }
            s[idx] = refStr[ptr];
            --counter[ptr];
        }
        return s;
    }
};
