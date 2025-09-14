struct Solution {
    inline bool doesAliceWin(string_view s) {
        return ranges::find_if(s, [](char c){return ((0x208222 >> (c & 31)) & 1) != 0;}) != s.end();
    }
};
