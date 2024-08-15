#include <regex>

struct Solution {
    const static regex wholePatt;

    bool isNumber(const string& s) {
        return regex_match(s, this->wholePatt);
    }
};
const regex Solution::wholePatt{regex(
    "^(?:(?:[+-]?\\d+)|(?:[+-]?(?:\\d+\\.\\d*|\\.\\d+)))(?:[eE][+-]?\\d+)?$"
)};
