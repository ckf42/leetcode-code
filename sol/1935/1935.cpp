#include <ranges>

struct Solution {
    int canBeTypedWords(string_view text, string_view brokenLetters) {
        int mask = 0;
        for (char c : brokenLetters){
            mask |= 1 << (c - 'a');
        }
        int res = 0;
        for (const auto w : text | ranges::views::split(' ')){
            bool valid = true;
            for (char c : w){
                if (mask & (1 << (c - 'a'))){
                    valid = false;
                    break;
                }
            }
            res += valid;
        }
        return res;
    }
};
