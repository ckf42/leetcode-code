struct Solution {
    string largestGoodInteger(string_view num) {
        char prev = 0, maxChar = 0;
        int count = 0;
        for (char c : num){
            if (c != prev){
                if (count >= 3){
                    maxChar = max(maxChar, prev);
                }
                prev = c;
                count = 0;
            }
            ++count;
        }
        if (count >= 3){
            maxChar = max(maxChar, prev);
        }
        if (maxChar != 0){
            return string(3, maxChar);
        }
        return string();
    }
};
