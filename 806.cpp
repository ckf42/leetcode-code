#include <string_view>

struct Solution {
    vector<int> numberOfLines(const vector<int>& widths, string_view s) {
        int currWidth = 0, lineCount = 0;
        for (string_view::const_iterator it = s.cbegin();
             it != s.cend();
             ++it){
            int newWidth = currWidth + widths[*it - 'a'];
            if (newWidth > 100){
                ++lineCount;
                currWidth = widths[*it - 'a'];
            } else {
                currWidth = newWidth;
            }
        }
        return vector<int>{lineCount + 1, currWidth};
    }
};
